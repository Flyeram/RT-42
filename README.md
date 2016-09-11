# RT

RT is a 42's project where you have to code a Raytracer with many possibilities. It was made by four people with SDL and can do the following :
+ Render sphere, cone, cylinder, plane and circle
+ Use multiple light spot
+ Manage object's shadow
+ Reflection
+ Transparence and refraction
+ Texture on sphere
+ Antialiasing
+ Some filter
+ Screenshot

# How to install

To compile on mac and linux `make re`.
You need SDL2 and SDL2_ttf to compile

# How to use
Run `./RT "scene filename"`. There is exemple of scene file in the `scenes` directory.  
`wa sd gt` to move around.  
`left/right` `top/bot` `pageup/pagedown` to rotate around.  
To process auto render mode, please see folder world.
If you just want to test it out, `./auto_render.sh world/world.auto`
