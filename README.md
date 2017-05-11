# Setup & Build instructions

----
## Windows 10
see also [Paraview's Wiki](http://www.paraview.org/Wiki/ParaView:Build_And_Install)

### Preparation:
* Install [Qt 5.8](https://www.qt.io/download-open-source) (both 32 and 64 bit versions)
* Install [CMake 3.8](https://cmake.org/download/)
* Install [MS-MPI v8](https://msdn.microsoft.com/en-us/library/bb524831(v=vs.85).aspx) (sdk + runtime)
* Install [Visual Studio 2015 Community](https://drive.google.com/open?id=0BzDYQBRp4j3nZS04R0NKdmVJbFE)
* Download [ParaView 5.3.0](http://www.paraview.org/download/)
* Extract Paraview into the following structure:
    * Paraview
        * build (empty)
        * src (all the content of the zip)
    * [cpDependencies.bat](https://drive.google.com/open?id=0BzDYQBRp4j3nVHp4M2VQdXhMN2s)

### CMake:
* Set source to Paraview/src/, dest to Paraview/build/
* Set Generator to VS14 2015 Win64
* Tick “Advanced” box
* Run Configure
    * Change PARAVIEW_QT_VERSION to 5
    * Check PARAVIEW_USE_MPI
* Run Configure
    * Check PARAVIEW_BUILD_PLUGIN_VRPlugin
    * Change Qt5_DIR to C:/Qt/5.8/msvc2015_64/lib/cmake/Qt5
* Run Configure
    * Change QT_HELP_GENERATOR to C:/Qt/5.8/msvc2015_64/bin/qhelpgenerator.exe
    * Change QT_XMLPATTERNS_EXECUTABLE to C:/Qt/5.8/msvc2015_64/bin/xmlpatterns.exe
    * Check PARAVIEW_AUTOLOAD_PLUGIN_VRPlugin
* Run Configure
* Run Generate

### Pre-Visual Studio:
* Append C:\Qt\5.8\msvc2015_64\bin to PATH System Environment Variable
* Run cpDependencies.bat and check that it’s copying everything
* Click “Open Project in VS” in CMake

### Visual Studio:
* Install Qt Visual Studio Tools from Extensions and Updates. Restart VS as requested
* Wait for Visual Studio to load and parse everything. 
* Build > Build Solution
* *Go grab a beer. It’s gonna take a while.*

### Run:
* Run Paraview (Paraview/build/bin/Debug/Paraview.exe)
* **BOOM DONE.**

----
## Ubuntu 16.04 LTS

### Preparation:
* Start from fresh Ubuntu 16.04 installation
* `sudo apt-get update; sudo apt-get upgrade`

* `sudo apt-get install git libncurses5-dev nvidia-375 mesa-common-dev libgles2-mesa-dev freeglut3-dev`
* Reboot
* Download CMake v3.8.1 Linux binaries: 
    * `cd ~/Downloads/`
    * `git clone https://github.com/Kitware/CMake.git` (v3.8.1)
    * `cd CMake`
    * `./bootstrap`
    * `make -j 12`
    * `sudo make install`
* Install Qt from sources
    * `cd ~/Downloads/`
    * `wget http://download.qt.io/official_releases/qt/5.8/5.8.0/qt-opensource-linux-x64-5.8.0.run`
    * `chmod u+x qt-opensource-linux-x64-5.8.0.run`
    * `./qt-opensource-linux-x64-5.8.0.run`
    * Login with vrcranfield@gmail.com;aeroelasticitydoorVR666
    * `sudo nano ~/.bashrc`, append at the end the following lines:
        * `export QTDIR=/home/vr/Qt5.8.0/5.8/gcc_64`
        * `export PATH=$QTDIR/bin:$PATH`
        * `export LD_LIBRARY_PATH=$QTDIR/lib:$LD_LIBRARY_PATH`
* Install OpenMPI (and other things)
    * `sudo apt-get install libphonon-dev libphonon4 libxt-dev libopenmpi-dev openmpi-common openmpi-bin python-dev`
* Install VRPN
    * `cd ~/Downloads`
    * `git clone https://github.com/vrpn/vrpn.git`
    * `cd vrpn`
    * `mkdir src`
    * `mv    * src`
    * `mkdir build`
    * `cd build`
    * `ccmake ../src`
    * `configure x2`
    * `generate`
    * `make -j 12`
    * `sudo make install`
* Install Protobuf
    * `cd ~/Downloads`
    * `wget https://github.com/google/protobuf/releases/download/v2.6.0/protobuf-2.6.0.tar.gz`
    * `tar xvf protobuf-2.6.0`
    * `cd protobuf-2.6.0`
    * `./configure`
    * `make -j 12`
    * `sudo make install`
    * `sudo apt-get install libprotoc9v5`
* Download ParaView from git:
    * `cd ~/Downloads`
    * `git clone https://gitlab.kitware.com/paraview/paraview.git`
    * `cd paraview`
    * `git submodule update --init`
    * `mkdir src`
    * `mv    * src`
    * `mkdir build`
    * `cd build`
    * `ccmake ../src`

### CMake:
*(at every configure step it may complain about a policy. Press e to ignore)*

* Run Configure
* Press `t` to enable advanced options
    * Change `Module_vtkRenderingOpenVR` to ON
    * Change `PARAVIEW_BUILD_PLUGIN_VRPlugin` to ON
    * Change `PARAVIEW_ENABLE_PYTHON` to ON
    * Change `PARAVIEW_USE_MPI` to ON
    * Change `VTK_USE_SYSTEM_PROTOBUF` to ON 
* Run Configure	
    * Change `PARAVIEW_AUTOLOAD_PLUGIN_VRPlugin` to ON
    * Change `PARAVIEW_USE_VRPN` to ON
* Run Configure x2
* Run Generate

### Compilation:
* `cd ~/Downloads/paraview/build`
* `make -j 12`
* *Go grab a beer. It’s gonna take a while (but less than in Windows).*

### Run:
* `cd ~/Downloads/paraview/build/bin`
* `./paraview` *(and pray your favourite god)*
* **BOOM DONE.**

	












