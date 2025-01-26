# Stella Flight Software
This repo contains the flight software for Stella flight computers.

## Setup
To set up your development environment to use this software:
1. **Install [Visual Studio Code](https://code.visualstudio.com/).**
2. **Install [git](https://git-scm.com/downloads/win).** Most of the install options can be left at defaults, but set the default editor to Visual Studio Code when asked.
3. **Clone this repository.** Open a new blank window in VSCode and click "Clone Repository" in the Source Control tab on the left. Then paste the link to this repo
   (https://github.com/LetSpace/StellaFlight.git) and choose a local folder to store the files in.
4. **Set up Extensions.** Ignore any messages about installing recommended extensions, and open the Profiles page (File > Preferences > Profile > Profiles). Then, in the
   dropdown next to "New Profile", click "Import Profile...", "Select File...", and choose `StellaFlight/.vscode/Pico.code-profile`. Then click "Create". This should install
   all the necessary extensions. Once it is finished, click the checkmark next to the Pico profile to apply it to the current window.

## Usage
To load this software onto the Stella board, simply connect the USB and click "Run" in the bottom toolbar. This project includes a `Restart Pico to BOOTSEL Mode` task that
should be triggered automatically, so there should be no need to unplug/plug to restart the Pico.
> [!NOTE]
> If you get an error that says a device was found but picotool was unable to connect, you may need to install a driver. Download and run [Zadig](http://zadig.akeo.ie/), select
> `RP2 Boot (Interface 1)` from the dropdown box and select `WinUSB` as the driver, and click on the "Install Driver" button. Wait for the installation to complete - this may
> take a few minutes.[^1]
[^1]: [Getting started with Raspberry Pi Pico-series](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf), page 26.
