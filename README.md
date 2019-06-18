# Interlace (il)

Interlace (`il`) is a command line tool that will interlace files for you like so:

`###text_file_1###
Hello`

`###text_file_2###
world`

`###text_file_3###
, this is so cool!`

`il text_file_1 text_file_2 text_file_3`

Will print:

`Hello
world
, this is so cool!`

This works with any number of files.

### Options:
`--stdin` or `-p` (for pipe) will pipe data in via stdin. This can also be used to type in a file interactively if you know how to type an EOF chracter :)

The thinking is, you can interlace your piped in data with another file like so:

`ps -aux | grep python | il -p process_data.txt`

