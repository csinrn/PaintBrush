# PaintBrush
implementation of Implementation of Aaron Hertzmann's paper "Painterly Rendering with Curved Brush Strokes of Multiple Sizes".


### To test the code
Install g++ opencv4, and cmake
ensure cmd command ```pkg-config opencv4 --cflags --libs``` return all opencv4 dependencies
for example:
```
$pkg-config opencv4 --cflags --libs
-I/usr/local/Cellar/opencv/4.5.1_3/include/opencv4 -L/usr/local/Cellar/opencv/4.5.1_3/lib -lopencv_gapi -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_mcc -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_sfm -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_highgui -lopencv_datasets -lopencv_text -lopencv_plot -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_xfeatures2d -lopencv_shape -lopencv_ml -lopencv_ximgproc -lopencv_video -lopencv_dnn -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core
```

After make sure opencv is installed, run
```
make
./finalProject.o [path to source video]         # default in opencv DIVX encoding
./finalProject.o [path to source video] MJPEG   # use MJPEG encoding instead
```
the window will show the processed frame, and f.avi will be created in the current directory.

### To Use the Library
There are two class in this code. Para.hpp is the class to store all parameters, and Paint.hpp is to implement the painting algorithm.
Include Para.hpp and Paint.hpp, and call paint() function in Paint.hpp for each frame you would like to process.
Check finalProject.cpp for an example.

A demo of how th layers are painted
<img width="448" alt="Screen Shot 2021-06-28 at 11 26 53 PM" src="https://user-images.githubusercontent.com/24727472/123725475-b102c000-d8c0-11eb-8733-efa607cbf101.png">Screen Shot 2021-06-28 at 11.26.57 PM.png<img width="448" alt="Screen Shot 2021-06-28 at 11 26 57 PM" src="https://user-images.githubusercontent.com/24727472/123725557-d5f73300-d8c0-11eb-8edc-6453fa999b64.png">Screen Shot 2021-06-28 at 11.27.01 PM.png<img width="448" alt="Screen Shot 2021-06-28 at 11 27 01 PM" src="https://user-images.githubusercontent.com/24727472/123725571-dabbe700-d8c0-11eb-89ba-45ec0988c4fd.png">Screen Shot 2021-06-28 at 11.27.04 PM.png<img width="448" alt="Screen Shot 2021-06-28 at 11 27 04 PM" src="https://user-images.githubusercontent.com/24727472/123725577-de4f6e00-d8c0-11eb-95e5-a07521adbf83.png">Screen Shot 2021-06-28 at 11.27.07 PM.png<img width="448" alt="Screen Shot 2021-06-28 at 11 27 07 PM" src="https://user-images.githubusercontent.com/24727472/123725594-e90a0300-d8c0-11eb-93d1-547601e51a37.png">Screen Shot 2021-06-28 at 11.27.43 PM.png<img width="448" alt="Screen Shot 2021-06-28 at 11 27 43 PM" src="https://user-images.githubusercontent.com/24727472/123725627-f9ba7900-d8c0-11eb-8584-e7171bd69a60.png">





