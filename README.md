# Setup & Build instructions on Windows 10
see also [Paraview's Wiki](http://www.paraview.org/Wiki/ParaView:Build_And_Install)

## Preparation:
* Install [Qt 5.8](https://www.qt.io/download-open-source) (both 32 and 64 bit versions)
* Install [CMake 3.8](https://cmake.org/download/)
* Install [MS-MPI v8](https://msdn.microsoft.com/en-us/library/bb524831(v=vs.85).aspx) (sdk + runtime)
* Install [Visual Studio 2015 Community](https://drive.google.com/open?id=0BzDYQBRp4j3nZS04R0NKdmVJbFE)
* Set up SDL2
	* Download [SDL2 source](https://www.libsdl.org/release/SDL2-2.0.5.zip)
	* Unzip the source code
	* Open a Powershell to the unzipped location
	* `mkdir build`
	* `cd build`
	* `cmake ..`
	* Open Visual Studio **AS ADMINISTRATOR**
	* Load the solution in `SDL/build/SLD2.sln`
	* Build the project `INSTALL` (it will install things in `C:/Program Files (x86)/SLD2)
* Take ParaView from our [repo](https://github.com/vrcranfield/vr)
	* `git clone https://github.com/vrcranfield/vr`

## CMake:
* Set source to `Paraview/src/`, dest to `Paraview/build/`
* Set Generator to VS14 2015 Win64
* Tick “Advanced” box
* Run Configure
	* Check `Module_vtkRenderingOpenVR`
    * Check `PARAVIEW_BUILD_PLUGIN_VRPlugin`
* Run Configure
	* Set `OPENVR_ROOT_DIR` to `[Paraview]/src/OpenVR/` (replace `[Paraview]` with path to repo)
* Run Configure
	* Set `SDL2MAIN_LIBRARY` to `C:/Program Files (x86)/SLD2/lib/SDL2main.lib`
	* Set `SDL2_LIBRARY_TEMP` to `C:/Program Files (x86)/SLD2/lib/SDL.lib`
	* Set `SDL2_INCLUDE_DIR` to `C:/Program Files (x86)/SLD2/include`
* Run Configure
    * Check `PARAVIEW_AUTOLOAD_PLUGIN_VRPlugin`
* Run Configure
* Run Generate

## Pre-Visual Studio:
* Append `C:\Qt\5.8\msvc2015_64\bin` to `PATH` System Environment Variable
* Run `cpDependencies.bat` and check that it’s copying everything
* Click “Open Project in VS” in CMake

## Visual Studio:
* Install Qt Visual Studio Tools from Extensions and Updates. Restart VS as requested
* Wait for Visual Studio to load and parse everything. 
* Build > Build Solution
* *Go grab a beer. It’s gonna take a while.*

## Run:
* Run Paraview (`Paraview/build/bin/Debug/Paraview.exe`)
* **BOOM DONE.**