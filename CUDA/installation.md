# CUDA
## Test Environment
- Ubuntu 14.04 64bit

## Download
- Version 8.0
```bash
 wget -bqc http://developer.nvidia.com/compute/cuda/8.0/prod/local_installers/cuda-repo-ubuntu1404-8-0-local_8.0.44-1_amd64-deb
```

## Installation
```bash
chmod +x cuda-repo-ubuntu1404-8-0-local_8.0.44-1_amd64-deb
sudo dpkg -i cuda-repo-ubuntu1404-8-0-local_8.0.44-1_amd64-deb
sudo apt-get update
sudo apt-get install cuda
sudo reboot
```
## Checking the version
```bash
$ nvcc --version
nvcc: NVIDIA (R) Cuda compiler driver
Copyright (c) 2005-2016 NVIDIA Corporation
Built on Sun_Sep__4_22:14:01_CDT_2016
Cuda compilation tools, release 8.0, V8.0.44
```
:tada::tada::tada:

## Test
```bash
$ cp -r /usr/local/cuda-8.0/samples ~/work/CUDA-samples
Test (make & excute) --> samples/1_Utilities/deviceQuery
```
## Setting up the environment variables
in ~/.bashrc

```bash
export PATH=/usr/local/cuda-8.0/bin:$PATH
export CUDA_HOME=/usr/local/cuda-8.0/
export LD_LIBRARY_PATH=/usr/local/cuda-8.0/lib64:$LD_LIBRARY_PATH
```
