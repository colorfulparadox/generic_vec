@echo off

IF "%1"=="" (
    echo No argument provided. Please specify 'build' or 'clean'.
    exit /b
)

IF "%1"=="build" (
    IF NOT EXIST target (
        mkdir target
    )

    gcc -pedantic -Wall --std=c17 src/main.c src/vector.c -o target/main.exe

    target\main.exe

    pause

    cls
    
) ELSE IF "%1"=="clean" (
    IF EXIST target (
        rmdir /s /q target
    )

) ELSE (
    echo Invalid argument. Please specify 'build' or 'cleanup'.
    exit /b
)