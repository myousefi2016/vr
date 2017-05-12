# Setup & Build instructions on Windows 10
see also [Paraview's Wiki](http://www.paraview.org/Wiki/ParaView:Build_And_Install)

## Preparation:
* Install [Qt 5.8](https://www.qt.io/download-open-source) (both 32 and 64 bit versions)
	* Append `C:\Qt\5.8\msvc2015_64\bin` to `PATH` System Environment Variable
	* Substitute `C:\Qt\5.8\msvc2015_64\lib\cmake\Qt5Core\Qt5CoreMacros.cmake` with the file found [here](https://drive.google.com/file/d/0ByDlFL3T6833eWpuaXU2dWdhNDg/view?usp=sharing) *([relevant link](https://codereview.qt-project.org/#/c/184321/2/src/corelib/Qt5CoreMacros.cmake))*
* Install [CMake 3.8](https://cmake.org/download/)
* Install [Visual Studio 2015 Community](https://drive.google.com/open?id=0BzDYQBRp4j3nZS04R0NKdmVJbFE)
	* Install `Qt Visual Studio Tools` from Extensions and Updates.
	* Restart VS as requested
* Take ParaView from our [repo](https://github.com/vrcranfield/vr)
	* `git clone https://github.com/vrcranfield/vr`

## CMake:
* Set source to `Paraview/src/`, dest to `Paraview/src/build/` *(note that `build` is INSIDE `src`)*
* Set Generator to `Visual Studio 14 2015 Win64`
* Tick “Advanced” box
* Run Configure
* Run Generate
* Click “Open Project in VS” in CMake

## Visual Studio:
* Wait for Visual Studio to load and parse everything.
* Build > Build Solution
* *Go grab a beer. It’s gonna take a while.*

## Run:
* Run Paraview (`Paraview/src/build/bin/Debug/Paraview.exe`)
* **BOOM DONE.**
