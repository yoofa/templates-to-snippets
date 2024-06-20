# templates-to-snippets
Write code snippets in a human-readable format and automatically generate snippet files.

## how to run
add code templates files in templates directory
```
templates/
    cpp/
        misc.cc
        string/
            is_subsequence.cc
    java/
        ...
    ...
```

ruls: code snippet should write like belows
```
// @snippets-start
// @snippets-generate true
// @snippets-prefix cp_is_subsequence
// @snippets-description check if sub is a subsequence of main

// @snippets-end
```
then run `python scripts/generate_snippets.py` to generate snippets json file

## use with neovim
`cp snippets/*.json to ~/.config/nvim/snippets`

or how i use:

`ln -sfv {$ABSOLUTE_PATH_OF_PROJECT}/snippets ~/.config/nvim/snippets/competitive_programming`
