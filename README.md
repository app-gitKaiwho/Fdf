# Fdf
### Info
  >42 Project about drawing wireframe.<br>
  >This project uses the minilibx from : https://github.com/42Paris/minilibx-linux

![](https://github.com/app-gitKaiwho/Fdf/blob/main/42.gif)

### How to use
  >After compiling, use "./fdf mapname.fdf".<br>
  >Usable map stored under ./test_maps are used (same goes if you want to create a new one)
 
### Explanation
  >I used Raycasting (which was i belive unusefully complex for this project)
  >even if in the end the raycast calcultion is nothing more than similar triangles formula

<img src="https://github.com/app-gitKaiwho/Fdf/assets/71593397/3f303ae4-3cbe-4b50-a8e7-abdc41bcebdc" width="30%" height="30%" />
<img src="https://github.com/app-gitKaiwho/Fdf/assets/71593397/40ac2c03-db3c-461f-8f74-cce3e3c60d0e" width="43.8%" height="43.8%" />

### Issues
  >One big issue with my code :<br>
  >for an easy coloring based on height, every single pixel is casted after lines are being drawn,
  >and not before which causes bad  performance on big maps may correct later
