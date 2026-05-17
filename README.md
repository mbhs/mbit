# How to update [mbit.mbhs.edu](https://mbit.mbhs.edu)

1. Clone the repository onto your computer.
2. Development:
    1. cd into the directory
    2. Run `staticjinja watch` to automatically re-render files
        - [Install `staticjinja`](https://staticjinja.github.io/staticjinja/)
    3. Run `sass -w ./sass/style.scss:./style.scss` to automatically recompile css
        - [Install dart sass](https://sass-lang.com/dart-sass/)
    4. Run `http.server` to host the server on `http://localhost:8000`
3. Commit and push your changes to github.
4. On bonx, cd into `/srv/http/mbit` and run `git pull`
