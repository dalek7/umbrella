
# Download ndk-r10e
refer to https://github.com/dalek7/umbrella/blob/master/NDK/download.md

# Execution
chmod +x '~/toolkits/android-ndk-r10e-linux-x86_64.bin' 

#.bashrc
export ANDROID_SDK_ROOT=~/FL/toolkits/Android/android-sdk-linux

export PATH=$PATH:$ANDROID_SDK_ROOT

export PATH=$PATH:~/FL/toolkits/Android/android-sdk-linux/platform-tools

**export NDK_ROOT=~/FL/toolkits/Android/android-ndk-r10e**

**export PATH=$PATH:$NDK_ROOT**

# Extracting the toolchain
**sudo ~/FL/toolkits/Android/android-ndk-r10e/build/tools/make-standalone-toolchain.sh --toolchain=arm-linux-androideabi-4.9 --platform=android-17 --ndk-dir=~/FL/toolkits/Android/android-ndk-r10e --install-dir=/opt/android-10-toolchain**

WARNING: The shell running this script isn't bash.  Although we try to avoid bashism in scripts, things can happen.

Copying prebuilt binaries...

Copying sysroot headers and libraries...

Copying c++ runtime headers and libraries...

Copying files to: /opt/android-10-toolchain

Cleaning up...

Done.

$ls /opt

android-10-toolchain

