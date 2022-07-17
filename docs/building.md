# Building a Toolchain with Docker

## Preperation

You need to have [Docker]() and [Qemu]() installed on your System. (Note: If you working at Windows don't forget to add Qemu to your Path. See this [Tutorial](). Then clone with Git this Project, or alternatively you can download this Project trough GitHub. When you have everything done go to the next step.

## Building Docker Container

Go into the Directory you have the Project cloned or downloaded, then change the Directory to `buildenv`. First you must decide for which Archtecture you want to build this Project. Currently is 'i686' and 'x86_64' as toolchain supported. Now type 'docker build <your arch> -t <your arch>-toolchain'. The Building process will may take a while (20 Minutes)
  
## Enter the Docker Container

 Enter build environment:
 - Linux or MacOS: `docker run --rm -it -v "$(pwd)":/root/env <your arch>-toolchain`
 - Windows Command Prompt: `docker run --rm -it -v "%cd%":/root/env <your arch>-toolchain`
 - PowerShell: `docker run --rm -it -v "${pwd}:/root/env" <your arch>-toolchain`
 - NOTE: If you are having trouble with an unshared drive, ensure your docker daemon has access to the drive you're development environment is in. For Docker Desktop, this is in "Settings > Shared Drives" or "Settings > Resources > File Sharing".

## Delete the Docker Container
  
For removing the Docker Container type: `docker rmi <your arch>-toolchain -f`
