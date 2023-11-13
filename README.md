<p align="center">
    <img src="https://i.imgur.com/UkiM2LM.png" width="256">
</p>
<p align="center">
    <a href="https://arma4ever.pl/">
        <img src="https://img.shields.io/badge/Forum-Do%C5%82%C4%85cz-1d8521" alt="A4E Forum">
    </a>
    <a href="https://discord.com/invite/bUawduRKSC">
        <img src="https://img.shields.io/badge/Discord-Do%C5%82%C4%85cz-darkviolet" alt="A4E Discord">
    </a>
   <a href="https://www.youtube.com/@arma4everpl">
        <img src="https://img.shields.io/badge/YouTube-Subskrybuj-c4302b" alt="A4E YouTube">
    </a>
    <a href="https://github.com/Krzyciu/simpleArtilleryComputer/blob/main/LICENSE">
        <img src="https://img.shields.io/badge/License-GPL_3.0-yellow" alt="Mod License">
    </a>
</p>

# Simple Artillery Computer
Default Arma 3 artillery computer is not suitable for milsim-coop gameplay as it's point&click nature seems to be way too unrealistic.</br>
However playing with disabled artillery computer makes artillery support way slower, especially when manned by unexperienced player.</br>
Here is where <b>Simple Artillery Computer</b> comes into play. 

## Usage
- To open computer, player must have <b>Artillery Computer</b> item in equipment.
- Press "P" or use ACE Self-Interaction to open dialog - button changable in addon's control options under [Simple Artillery Computer].
- Select range to target - drop-down list on left, range is based on selected charge.
- Enter own position - Grid reference, at least xxx-yyy grid is required - center position of grid will be taken. Up to 10 digits grid reference is supported (1m precision)
- (Optional) If player has GPS or ACE Microdagr in equipment, it's possible to get own position through "GPS" button click.
- Enter target position - same as enter own position.
- Click "Calculate" button - Computer will fill gun elevation, distance and direction to target. Elevation and direction is show in [mils](https://en.wikipedia.org/wiki/Milliradian). If any of input parameters is not suitable, error on systemChat will be thrown.

## Key-notes:
- Terrain elevation is taken into account during calculation. No need to manually add correction.
- All data - both input and output is saved on display closure.
- It's advised to make sure that gunner selected proper charge on gun.

## Requirements
Newest versions of:
- [CBA](https://github.com/CBATeam/CBA_A3)
- [ACE3](https://github.com/acemod/ACE3)

## Credits 
Scripts and addons macros are based on [ACE3](https://github.com/acemod/ACE3) and [CBA](https://github.com/CBATeam/CBA_A3) projects.  

## License
[GPL 3.0](https://github.com/Krzyciu/simpleArtilleryComputer/blob/main/LICENSE)
