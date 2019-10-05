# Pull base image
FROM ubuntu:16.04

# Install
RUN cd /home \
    && apt-get update \  # install git
    && apt-get -y upgrade \ 
    --assume-yes vim \
    && apt-get install --assume-yes git \
        tree        \
        tmux        \
        htop        \
        unzip       \
        python3     \
        python3-pip \
    # && pip install -r 
    && apt-get install --assume-yes python3-dev \
    && apt-get install --assume-yes build-essential \
    && apt-get install --assume-yes 
    && apt-get install --assume-yes g++ \
    && apt-get install --assume-yes gcc \
    && apt-get install --assume-yes libboost-all-dev \  # install boost

# Add files
ADD root/.gitconfig /root/.gitconfig

# Set environment variable
ENV HOME /root

# Define working directory
WORKDIR /root

# Define default command
CMD ["bash]

