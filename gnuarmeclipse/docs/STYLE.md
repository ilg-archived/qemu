
## C

[QEMU Coding Style](http://git.qemu-project.org/?p=qemu.git;a=blob_plain;f=CODING_STYLE;hb=HEAD)

- indents are four spaces
- tabs are never used
- lines are 80 characters
- variables are **lower\_case\_with\_underscores**
- structured type names are in **CamelCase**
- sScalar type names are **lower\_case\_with\_underscores\_ending\_with\_a\_t**
- declarations should be at the beginning of blocks (?!)

Block structure:

    if (a == 5) {
        printf("a was 5.\n");
    } else if (a == 6) {
        printf("a was 6.\n");
    } else {
        printf("a was something else entirely.\n");
    }

    void a_function(void)
    {
        do_something();
    }


## QOM (QEMU Object Model)

[QOM Conventions](http://wiki.qemu.org/QOMConventions)

- DO use names-separated-by-dashes

