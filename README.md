# Demo-recorder
[![sampctl](https://shields.southcla.ws/badge/sampctl-Demo--Recorder-2f2f2f.svg?style=for-the-badge)](https://github.com/y/Demo-Recorder)  

An include that records demos of players.  

# Installation<br/>
<br/>
Simply install to your project:<br/>

```bash
sampctl package install RogueDrifter/Demo-recorder
```
<br/>
Include in your code and begin using the library:<br/>

```pawn
#include <DemoRecorder>
```
# Testing<br/>
<br/>
To test, simply run the package:<br/>

```bash
sampctl package run
```

Purpose of this is just as a fallback if you wanna confirm someone cheated or anything, concept is very easy as well just include it in your gamemode and everything is done on its own, check for the saved NPC files in your server folder with the player name starting with DEMO_ and ending with either _VEHICLE or _FOOT

FAQ:
```
1- So this catches all cheaters? No because it overwrites so things will go missing.  

2- Will this fill up my space with recorded files? No because it overwrites the files per-player  

3- So how does it work? Once someone connects a file is set under their name on foot, that changes every time they get in/out of a car and it gets overwritten, so every player can only have 2 files, one inside of a car and one on-foot.  

4- How do i play it? If you've ever used NPCs you'll know how to get it done, just spectate the NPC once you play the recorded file if you wanna check for anything.```
