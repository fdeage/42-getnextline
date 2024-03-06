# 42-get_next_line

## Overview

`gnl` is a convenient utility to get the next line from a file descriptor. It can handle up to 512 files of arbitrary lengths.

It needs the `libft` library to work. This repo doesn't include the `libft` source files, but includes an already-compiled `libft.a`. The `libft` sources can be found [here](https://github.com/fdeage/42-libft).

`get_next_line` is a first-year project from the [42](#42) school, which I attended in 2013-2016. It abides to the strict rules of 42 not to exceed 5 functions per file, or 25 lines per function.


## Getting started

To compile the project:
```
?> ./make
```

Then you can pass it several files (up to 512):
```
?> ./gnl <file1> <file2>
```

`gnl` is a library but is compiled with a main by default.
If you only want the library:
```
?> ./make lib
```


## 42

[42](https://www.42.fr) is a French programming school founded in 2013, rooted in P2P collaboration and self-directed learning. Its pedagogy is fully project-based. It is considered a [good place](https://twitter.com/paulg/status/847844863727087616) to learn to code.


## License

This project is licensed under the [MIT license](LICENSE).


## Author

This project was created by Félix Déage.
