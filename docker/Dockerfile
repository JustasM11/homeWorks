FROM ubuntu:latest

# Set the working directory
WORKDIR /home/docker

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive TZ=Etc/UTC apt-get -y install g++ make cmake git gcovr
RUN git clone --depth 1  https://github.com/google/googletest.git
RUN chmod -R 777 /home/docker
