# PaintBrush
Implementation of Aaron Hertzmann's paper "Painterly Rendering with Curved Brush Strokes of Multiple Sizes".


### To test the code
Install g++ opencv4, and cmake
ensure cmd command ```pkg-config opencv4 --cflags --libs``` returns all opencv4 dependencies
for example:
```
$pkg-config opencv4 --cflags --libs
-I/usr/local/Cellar/opencv/4.5.1_3/include/opencv4 -L/usr/local/Cellar/opencv/4.5.1_3/lib -lopencv_gapi -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_mcc -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_highgui -lopencv_datasets -lopencv_text -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_dnn -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core
```

After make sure opencv is installed, run
```
$ make
$ ./finalProject.o [path to source video]         # default in opencv DIVX encoding for a better quality, some video players may have trouble opening the file with this encoding
$ ./finalProject.o [path to source video] MJPEG   # use MJPEG encoding instead
```
the window will show the processed frame, and f.avi will be created in the current directory.

### To Use the Library
There are two classes in this code. Para.hpp is the class to store all parameters, and Paint.hpp is to implement the painting algorithm.
Include Para.hpp and Paint.hpp, and call paint() function in Paint.hpp for each frame you would like to process.
Check finalProject.cpp for an example.

A demo of how th layers are painted  
![demoPicture](https://user-images.githubusercontent.com/24727472/123726840-40a96e00-d8c3-11eb-804b-c5b544db9ec3.jpg)
Original  
<img width="400" alt="Screen Shot 2021-06-29 at 10 11 35 AM" src="https://user-images.githubusercontent.com/24727472/123726846-443cf500-d8c3-11eb-813e-302f322d51f8.png">Layer1  
<img width="400" alt="Screen Shot 2021-06-29 at 10 11 40 AM" src="https://user-images.githubusercontent.com/24727472/123726850-4606b880-d8c3-11eb-888d-d71257d857a4.png">Layer2  
<img width="400" alt="Screen Shot 2021-06-29 at 10 11 44 AM" src="https://user-images.githubusercontent.com/24727472/123726858-499a3f80-d8c3-11eb-9573-aec468edeae4.png">Layer3  
<img width="400" alt="Screen Shot 2021-06-29 at 10 11 47 AM" src="https://user-images.githubusercontent.com/24727472/123726869-4dc65d00-d8c3-11eb-8afb-b3545b7c3871.png">Layer4  
<img width="400" alt="Screen Shot 2021-06-29 at 10 11 50 AM" src="https://user-images.githubusercontent.com/24727472/123726877-50c14d80-d8c3-11eb-8461-f5a3fcd2efb1.png">Layer5  
<img width="400" alt="Screen Shot 2021-06-29 at 10 11 58 AM" src="https://user-images.githubusercontent.com/24727472/123726883-528b1100-d8c3-11eb-8c04-661e7b97df29.png">Final





