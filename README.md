# Beach-Blitz-Vision-2020-Examples

These are the examples accompanying my workshop slides for Beach Blitz 2020. Feel free to open an issue on this project if you want to see any more examples or need clarification on anything. Also take a look at the FRC-2020-Vision and FRC-2019-Vision repositories at: https://github.com/FRC3476

The slides can be found here: 

Each example is in a self-contained folder. To build and run, try the following:

```
cd HSVFilter
cmake .
make all 
./HSVFilter
```
The included samples are 
1. BasicTest - Opens a webcam stream and displays images 
2. HSVFilter - Demos filtering based on color 
3. Morphology - Demos noise removal using the morphology filtering 
4. ExtractionPipeline - Demos how to extract interesting potential vision targets 
5. GStreamer - Shows how you can use GStreamer to debug your vision and stream annotated camera frames to the DS
6. Blurs - Shows how to do noise removal with a blur
