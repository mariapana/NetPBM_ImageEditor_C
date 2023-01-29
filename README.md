##### Copyright Maria Pana 315CA <maria.pana4@gmail.com> 2022-2023

```

████████ ███████ ███    ███  █████      ██████                ██████   ██████ ██      ██████  
   ██    ██      ████  ████ ██   ██          ██               ██   ██ ██      ██      ██   ██ 
   ██    █████   ██ ████ ██ ███████      █████      █████     ██████  ██      ██      ██████  
   ██    ██      ██  ██  ██ ██   ██          ██               ██      ██      ██      ██      
   ██    ███████ ██      ██ ██   ██     ██████                ██       ██████ ███████ ██      
                                                                                              
```
# Description - NetPBM image editor in C
_compatible file types_: PGM (P2, P5), PPM (P3, P6)
```
Homework no. 3 for the Programming Computers and Programming Langauges course
CA 2022, Faculty of Automatic Control and Computer Science, UPB
(Univeristy POLITEHNICA of Bucharest)
```
## How to use
The program receives input via CLI (Command Line Interface) by typing in the
following commands:
```
- LOAD <file_name>
- SELECT <x1> <y1> <x2> <y2>
- SELECT ALL
- HISTOGRAM <stars> <bins>
- EQUALIZE
- ROTATE <angle>
- CROP
- APPLY <effect>
- SAVE
- EXIT
```

## How the images are stored
_relevant files: `struct_def.h`_

Each image is retained in a *struct* called `image` which contains elements
retaining each property:
- `type`: depending on the magic word, the type of the image can be:
```
    2 if the magic word is P2 (grayscale ASCII file)
    5 if the magic word is P5 (grayscale binary file)
    3 if the magic word is P3 (coloured ASCII file)
    6 if the magic word is P6 (coloured binary file)
```
- `width` and `height`
- `x1`, `y1`, `x2`, `y2`: coordinates of the selected bits/pixels
- `max_val`: the maximum value of any element within the bitmap/pixmap
- `bitmap` and `pixmap`: dynamically allocated matrices storing the given map
of values:

    The bitmap stores `bit` elements (also a struct that contains only one
    element `val`).  
    The pixmap stores `pixel` elements (also a struct that contains elements
    `r`, `g`, `b` to store red, green and blue values).
    Each element (val, r, g, b) is of type double.
    
Note: For each struct declaration, I prefered to use `typedef` in order to ease
future code reading and implementation.

Since the bitmap and pixmap are dynamically allocated matrices, I implemented a
series of functions that manage their memory and contents, which will be used
in future command implementations.

_relevant files: `memory_management.c`, `memory_management.h`,
`map_management.c`, `map_management.h`_

# Image editor commands
Note: The program always checks the validity of the inputted commands prior to
their execution (image loaded, correct coordinates, enough parameters etc.)
through string manipulation or pointer verifications. If any command crashes
or doesn't receive the adequate input, the program alerts the user through
error messages. Otherwise, the user will be prompted a succesful command
message.

The following explanations assume that all validity checks were passed
successfully.

## 1. Loading an image - LOAD <file_name> command
_relevant files: `load.c`, `load.h`_

Command LOAD loads in a new image (specified by the file name). If an image was
already loaded, the program frees the resources allocated previously.
(function `load()`)

Afterwards, if the file was opened correctly, the image data stored in the
input file will be also stored in the image struct (in our case called photo).
(function 'read_img()')

Note: Instead of memorising the magic word as a string (P2, P3, P5, P6), image
structs hold an character called type in which the correspondent number is
stored ('2', '3', '5', '6').

Functions `skip_to_eol()` and `check_for_comment()` are used to parse the input
file, mainly to ignore irrelevant information.


## 2. Selecting image areas - SELECT, SELECT ALL commands
_relevant files: `select.c`, `select.h`_

Command SELECT followed by its parameters (x1, y1, x2, y2) limits the area of
effect to the one described by the given coordinates. If SELECT is followed by
ALL, then the whole image is selected (equivalent to SELECT 0 0 width height).

At its execution, the command sets values x1, y1, x2, y2 in the image struct
to the ones given by the user.


## 3. Generating the histogram - HISTOGRAM command
_relevant files: `histogram.c`, `histogram.h`_

The command prints an ASCII histogram of a grayscale image to the console.
The user has to specify the maximum number of stars and the number of bins
the program can use.

In order to generate the visual of the histogram, the program first creates
a frequency vector storing the number of appearances of each value in the
bitmap. (function `populate_freq()`)

Note: The frequency vector is dynamically allocated. After the execution of
the command, its memory is free'd.

Next, the program uses * and | to display the resulted histogram (function
`display_histogram()`)


## 4. Equalizing the image - EQUALIZE command
_relevant files: `equalize.c`, `equalize.h`_

Similarly to the HISTOGRAM command, `equalize()` is applied only to grayscale
images and also creates a frequency vector using `populate_freq()`.

Based on the frequency vector, for each value in the bitmap, the program
computes `histo_sum` (sum i from 0 to the value of the pixel of freq[i]).
The result will be used to compute the new pixel value:
```
  new_val = histo_sum * 255.0 / area
```
where area = width * height.

Once the new value is calculated, the bitmap will be updated with each
iteration.


## 5. Filters and effects - APPLY command
_relevant files: `apply.c`, `apply.h`, `kernel.c`, `kernel.h`_

The command applies the following effects:
  - edge
  - sharpen
  - blur
  - gaussian blur

Example outputs: https://setosa.io/ev/image-kernels/,
https://en.wikipedia.org/wiki/Kernel_(image_processing)

Note: The command can be applied only to coloured images.

To achieve such outputs, the program multiplies each pixel and its 
surrounding neighbours (a 3x3 area) with the kernel corresponding
to the desired effect. The results will be summed together, resulting
in the new pixel value (function `convolution()`)

The new pixel values will be temporarily stored in a newly dynamically
allocated pixmap. (function `apply_effect()`)

The program also generates the necessary kernel matrix in `kernel.c`.


## 6. Cropping the image - CROP command
_relevant files: `crop.c`, `crop.h`_

To crop the picture, the program dynamically allocates a new bitmap/
pixmap but with the new post-cropping dimensions. For the selected area,
the values of the original bitmap will be copied in the new one.
Finally, the cropped version of the bitmap will replace the old one
(the old bitmap is free'd and its address will point to its new
version).

However, not only the bitmap is reduced in size. The width and height
are also affected by command and thereby updated.


## 7. Rotating the image - ROTATE command
_relevant files: `rotate.c`, `rotate.h`, `rotate_ss.c`, `rotate_ss.h`,
`rotate_wi.c`, `rotate_wi.h`_

The program rotates the image by an angle divisible by 90. If the angle
is negative, the rotation will be performed counter-clockwise. If the
angle is positive, the rotation will be performed clockwise.

To ease code reading and proofing, each type of rotation is defined
through its own function.

There are two main rotation classifications:

1. By the angle of rotation
Note: +-90 <=> -+270, 180 <=> -180, 0 and +-360 don't affect the
picture (and will be ignored).

2. By how much of the picture is rotated
  - square selection (ss)
  - whole image (wi)

There is a crucial difference in implementation between ss and wi
rotations: the second one also needs bitmap/pixmap reallocation when the
angle is +-90 o +-270 degrees.

With this purpose, the map will be replaced by a new dynamically
allocated one, whose dimensions are inversed (width becomes height,
height becomes width).

In general, the program uses a temporary map to place the values or
pixels in their new spots (according to their index formula).


## 8. SAVE
_relevant files: `save.c`, `save.h`_

Much like the LOAD command, SAVE also receives a file name (only
this time it will specify the output). The image data stored in
the struct will be printed into the file.

Since it should always be saved in ASCII, the header is printed
through function `transf_header()` no matter the type of the
output file.

The value maps, however, are printed depending on the file type
(ASCII/text or binary) through functions `transf_map_to_txt` and
`transf_map_to_bin`.

## 9. EXIT
_relevant files: `exit.c`, `exit.h`_

When the EXIT command is called, the program free's all dynamically
allocated resources (the bitmap / pixmap) and closes all opened
files (the input file).
