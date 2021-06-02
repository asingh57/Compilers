apt-get update
	vagrant plugin install vagrant-vbguest
    apt-get install --assume-yes \
      ant \
      cmake \
      g++ \
      git \
      maven \
      openjdk-11-jdk \
      pkg-config \
      unzip \
      uuid-dev
    #
    # Retrieve antlr 
    ANTLR_BUILD_DIR=$(mktemp -d /tmp/antlr.XXX)
    cd $ANTLR_BUILD_DIR
    wget http://www.antlr.org/download/antlr-4.9.1-complete.jar
    wget http://www.antlr.org/download/antlr4-cpp-runtime-4.9.1-source.zip
    wget http://www.antlr.org/download/antlr-runtime-4.9.1.jar
    #
    # Build c++ Antlr lib 
    mkdir tmp
    cd tmp
    unzip ../antlr4-cpp-runtime-4.9.1-source.zip
    mkdir build && cd build
    cmake ..
    make -j 2
    DESTDIR=/ make install
    cd ../..
    rm -rf tmp
    #
    # Install Java Antlr lib and set Classpath
    mv antlr-4.9.1-complete.jar /usr/local/lib/
    mv antlr-runtime-4.9.1.jar /usr/local/lib/
    echo 'export CLASSPATH=".:/usr/local/lib/antlr-4.9.1-complete.jar:$CLASSPATH"' >> /etc/profile.d/setClassPath.sh
    #
    # Create antlr link 
    echo '#!/bin/sh -ue' > /usr/bin/antlr
    echo 'java -jar /usr/local/lib/antlr-4.9.1-complete.jar $@' >> /usr/bin/antlr
    chmod 755 /usr/bin/antlr
    #
    # Build spim with keepstats
    apt-get install --assume-yes bison flex
    git clone https://github.com/rudyjantz/spim-keepstats
    cd spim-keepstats
    patch -p1 < /home/vagrant/spimfixes.patch
    cd spim
    make && make install
    apt-get remove --purge --assume-yes bison flex
    #
    #Clean up
    cd /tmp
    rm -rf $ANTLR_BUILD_DIR
    ldconfig

echo '#!/bin/sh -ue' > /usr/bin/grun
echo 'java -cp /usr/local/lib/antlr-4.9.1-complete.jar org.antlr.v4.gui.TestRig' >> /usr/bin/grun
chmod 755 /usr/bin/grun
ldconfig
