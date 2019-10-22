# FreeTACOS
Free Transparent Arinc Compliant Operating System

# Getting Started
Follow this guide for setting up Docker, Docker-Compose and Docker-Sync.

## Installation
**Install this:**

**Docker**: 
https://docs.docker.com/install/

**Docker-Compose**: 
https://docs.docker.com/v17.09/compose/install/

**Docker-Sync**: 
https://docker-sync.readthedocs.io/en/latest/getting-started/installation.html

## Start Containers
```Bash
$ make start # This will start the containers, including the sync (let this run in a terminal by itself - you can not terminate)
$ make enter # This will 'go into' the container, allowing you to compile the dependencies + project :)
```

### Circle Setup (Only required first time)
#### Use Make
```Bash
$ make build-boot # Build boot files
$ make enter # Enter docker container
$ cd aarch/rasp4 # Navigate to circle library
$ ./makeall clean # Clear dependencies
$ ./makeall # Compile dependencies - This must be done within the container
```

Done.

## Stop Containers
```Bash
# From circle/ root
$ docker-compose down # Closes the arinc_circle container
$ docker-sync stop # Closes the docker-sync container
```
OR
Interrupt CTRL+C the running docker-sync process

## Compile Generated Configuration File
### Prerequisites
Install Scala compiler (sbt) https://www.scala-sbt.org/

### Compile
Go to /ScheduleGenerator folder

```Bash
$ sbt run # Compile scala code and run the generator program
$ cd ../src # Enter the source folder
$ g++ -c --std=c++17 kernel/config.cpp -I apex/ -I types/ # Compile the generated config.cpp file
```