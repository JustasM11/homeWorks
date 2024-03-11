FROM ubuntu:20.04

# Set the working directory
WORKDIR /home/docker

RUN apt-get update
RUN apt-get -y install g++ make cmake git
RUN git clone --depth 1  https://github.com/google/googletest.git
RUN chmod -R 777 /home/docker
