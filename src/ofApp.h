#pragma once

#include "ofMain.h"

//file logging
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <sys/stat.h>

#include "inkPrint.h"
#include "shapeDetect.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void canvas(int alpha);
        void log();
        int logLength();
        inline bool fileExists (const string& name);
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        

        // global vars
        ofImage img;
        int count;
        string fileName;
        int w,h;

        // shape detect class
        shapeDetect inspiration;

        // print class
        inkPrint print;
        float p0000[4][2] = {{0,0},{0,0},{1,1},{0,1}};
        float p0001[5][2] = {{0,0},{1,0},{1,1},{0,1},{1,1}};
        float p0002[32][2] = {{0.141,0.000},{0.127,0.014},{0.070,0.014},{0.028,0.056},{0.028,0.070},{0.014,0.085},{0.014,0.127},{0.000,0.141},{0.000,0.845},{0.014,0.859},{0.014,0.887},{0.028,0.901},{0.028,0.930},{0.042,0.944},{0.056,0.944},{0.085,0.972},{0.127,0.972},{0.141,0.986},{0.859,0.986},{0.873,0.972},{0.901,0.972},{0.915,0.958},{0.930,0.958},{0.972,0.915},{0.972,0.887},{0.986,0.873},{0.986,0.113},{0.972,0.099},{0.972,0.070},{0.915,0.014},{0.887,0.014},{0.873,0.000}};
        float p0003[20][2] = {{0.040,0.000},{0.030,0.010},{0.020,0.010},{0.010,0.020},{0.010,0.030},{0.000,0.040},{0.000,0.430},{0.010,0.440},{0.010,0.460},{0.020,0.470},{0.970,0.470},{0.980,0.460},{0.980,0.440},{0.990,0.430},{0.990,0.040},{0.980,0.030},{0.980,0.020},{0.970,0.010},{0.960,0.010},{0.950,0.000}};
        float p0004[109][2] = {{0.215,0.000},{0.203,0.013},{0.203,0.038},{0.190,0.051},{0.190,0.076},{0.177,0.089},{0.177,0.101},{0.165,0.114},{0.165,0.139},{0.152,0.152},{0.152,0.165},{0.139,0.177},{0.139,0.203},{0.127,0.215},{0.127,0.241},{0.114,0.253},{0.114,0.266},{0.101,0.278},{0.101,0.304},{0.089,0.316},{0.089,0.329},{0.076,0.342},{0.076,0.367},{0.063,0.380},{0.063,0.405},{0.051,0.418},{0.051,0.430},{0.038,0.443},{0.038,0.468},{0.025,0.481},{0.025,0.506},{0.013,0.519},{0.013,0.532},{0.000,0.544},{0.000,0.582},{0.013,0.595},{0.025,0.595},{0.076,0.646},{0.089,0.646},{0.152,0.709},{0.165,0.709},{0.215,0.759},{0.228,0.759},{0.278,0.810},{0.291,0.810},{0.342,0.861},{0.354,0.861},{0.405,0.911},{0.418,0.911},{0.468,0.962},{0.481,0.962},{0.506,0.937},{0.519,0.937},{0.544,0.911},{0.557,0.911},{0.582,0.886},{0.595,0.886},{0.608,0.873},{0.620,0.873},{0.646,0.848},{0.658,0.848},{0.684,0.823},{0.696,0.823},{0.722,0.797},{0.734,0.797},{0.759,0.772},{0.772,0.772},{0.797,0.747},{0.810,0.747},{0.835,0.722},{0.848,0.722},{0.861,0.709},{0.873,0.709},{0.899,0.684},{0.911,0.684},{0.937,0.658},{0.949,0.658},{0.975,0.633},{0.987,0.633},{0.987,0.582},{0.975,0.570},{0.975,0.544},{0.962,0.532},{0.962,0.494},{0.949,0.481},{0.949,0.443},{0.937,0.430},{0.937,0.405},{0.924,0.392},{0.924,0.354},{0.911,0.342},{0.911,0.304},{0.899,0.291},{0.899,0.266},{0.886,0.253},{0.886,0.215},{0.873,0.203},{0.873,0.165},{0.861,0.152},{0.861,0.127},{0.848,0.114},{0.848,0.076},{0.835,0.063},{0.835,0.038},{0.823,0.025},{0.658,0.025},{0.646,0.013},{0.405,0.013},{0.392,0.000}};
        float p0005[113][2] = {{0.244,0.000},{0.244,0.013},{0.218,0.038},{0.218,0.051},{0.205,0.064},{0.205,0.077},{0.192,0.090},{0.192,0.103},{0.167,0.128},{0.167,0.141},{0.154,0.154},{0.154,0.167},{0.141,0.179},{0.141,0.192},{0.115,0.218},{0.115,0.231},{0.103,0.244},{0.103,0.256},{0.090,0.269},{0.090,0.282},{0.064,0.308},{0.064,0.321},{0.051,0.333},{0.051,0.346},{0.038,0.359},{0.038,0.372},{0.013,0.397},{0.013,0.410},{0.000,0.423},{0.000,0.436},{0.013,0.449},{0.013,0.462},{0.038,0.487},{0.038,0.500},{0.051,0.513},{0.051,0.526},{0.064,0.538},{0.064,0.551},{0.090,0.577},{0.090,0.590},{0.103,0.603},{0.103,0.615},{0.128,0.641},{0.128,0.654},{0.141,0.667},{0.141,0.679},{0.167,0.705},{0.167,0.718},{0.179,0.731},{0.179,0.744},{0.192,0.756},{0.192,0.769},{0.218,0.795},{0.218,0.808},{0.231,0.821},{0.231,0.833},{0.256,0.859},{0.744,0.859},{0.756,0.846},{0.756,0.833},{0.782,0.808},{0.782,0.795},{0.795,0.782},{0.795,0.769},{0.821,0.744},{0.821,0.731},{0.833,0.718},{0.833,0.705},{0.846,0.692},{0.846,0.679},{0.859,0.667},{0.859,0.654},{0.885,0.628},{0.885,0.615},{0.897,0.603},{0.897,0.590},{0.910,0.577},{0.910,0.564},{0.936,0.538},{0.936,0.526},{0.949,0.513},{0.949,0.500},{0.962,0.487},{0.962,0.474},{0.987,0.449},{0.987,0.410},{0.974,0.397},{0.974,0.385},{0.962,0.372},{0.962,0.359},{0.949,0.346},{0.949,0.333},{0.923,0.308},{0.923,0.295},{0.910,0.282},{0.910,0.269},{0.885,0.244},{0.885,0.231},{0.872,0.218},{0.872,0.205},{0.859,0.192},{0.859,0.179},{0.833,0.154},{0.833,0.141},{0.821,0.128},{0.821,0.115},{0.795,0.090},{0.795,0.077},{0.782,0.064},{0.782,0.051},{0.756,0.026},{0.756,0.013},{0.744,0.000}};
        float p0006[165][2] = {{0.281,0.000},{0.281,0.011},{0.258,0.034},{0.258,0.045},{0.236,0.067},{0.236,0.079},{0.225,0.090},{0.225,0.101},{0.202,0.124},{0.202,0.135},{0.191,0.146},{0.191,0.157},{0.169,0.180},{0.169,0.191},{0.157,0.202},{0.157,0.213},{0.135,0.236},{0.135,0.247},{0.124,0.258},{0.124,0.270},{0.101,0.292},{0.101,0.303},{0.090,0.315},{0.090,0.326},{0.067,0.348},{0.067,0.360},{0.056,0.371},{0.056,0.382},{0.034,0.404},{0.034,0.416},{0.022,0.427},{0.022,0.438},{0.000,0.461},{0.000,0.472},{0.011,0.472},{0.034,0.494},{0.045,0.494},{0.056,0.506},{0.067,0.506},{0.090,0.528},{0.101,0.528},{0.112,0.539},{0.124,0.539},{0.146,0.562},{0.157,0.562},{0.169,0.573},{0.180,0.573},{0.202,0.596},{0.213,0.596},{0.225,0.607},{0.236,0.607},{0.258,0.629},{0.270,0.629},{0.281,0.640},{0.292,0.640},{0.315,0.663},{0.326,0.663},{0.337,0.674},{0.348,0.674},{0.371,0.697},{0.382,0.697},{0.404,0.719},{0.416,0.719},{0.427,0.730},{0.438,0.730},{0.461,0.753},{0.472,0.753},{0.483,0.764},{0.494,0.764},{0.517,0.787},{0.528,0.787},{0.539,0.798},{0.551,0.798},{0.573,0.820},{0.584,0.820},{0.596,0.831},{0.607,0.831},{0.629,0.854},{0.640,0.854},{0.652,0.865},{0.663,0.865},{0.685,0.888},{0.708,0.888},{0.719,0.876},{0.719,0.865},{0.742,0.843},{0.742,0.831},{0.753,0.820},{0.753,0.809},{0.775,0.787},{0.775,0.775},{0.787,0.764},{0.787,0.753},{0.809,0.730},{0.809,0.719},{0.831,0.697},{0.831,0.685},{0.843,0.674},{0.843,0.663},{0.854,0.652},{0.854,0.640},{0.876,0.618},{0.876,0.607},{0.899,0.584},{0.899,0.573},{0.910,0.562},{0.910,0.551},{0.933,0.528},{0.933,0.517},{0.944,0.506},{0.944,0.494},{0.966,0.472},{0.966,0.461},{0.978,0.449},{0.978,0.438},{0.989,0.427},{0.989,0.416},{0.978,0.416},{0.955,0.393},{0.944,0.393},{0.921,0.371},{0.910,0.371},{0.899,0.360},{0.888,0.360},{0.865,0.337},{0.854,0.337},{0.843,0.326},{0.831,0.326},{0.809,0.303},{0.798,0.303},{0.787,0.292},{0.775,0.292},{0.753,0.270},{0.742,0.270},{0.730,0.258},{0.719,0.258},{0.697,0.236},{0.685,0.236},{0.663,0.213},{0.652,0.213},{0.640,0.202},{0.629,0.202},{0.618,0.191},{0.607,0.191},{0.584,0.169},{0.573,0.169},{0.562,0.157},{0.551,0.157},{0.528,0.135},{0.517,0.135},{0.506,0.124},{0.494,0.124},{0.472,0.101},{0.461,0.101},{0.438,0.079},{0.427,0.079},{0.416,0.067},{0.404,0.067},{0.382,0.045},{0.371,0.045},{0.360,0.034},{0.348,0.034},{0.326,0.011},{0.315,0.011},{0.303,0.000}};
        float p0007[61][2] = {{0.110,0.000},{0.110,0.010},{0.100,0.020},{0.100,0.110},{0.090,0.120},{0.090,0.190},{0.080,0.200},{0.080,0.290},{0.070,0.300},{0.070,0.370},{0.060,0.380},{0.060,0.470},{0.050,0.480},{0.050,0.550},{0.040,0.560},{0.040,0.640},{0.030,0.650},{0.030,0.720},{0.020,0.730},{0.020,0.830},{0.010,0.840},{0.010,0.900},{0.000,0.910},{0.000,0.950},{0.010,0.960},{0.080,0.960},{0.090,0.970},{0.180,0.970},{0.190,0.980},{0.250,0.980},{0.260,0.990},{0.330,0.990},{0.340,0.980},{0.340,0.920},{0.350,0.910},{0.350,0.820},{0.360,0.810},{0.360,0.740},{0.370,0.730},{0.370,0.640},{0.380,0.630},{0.380,0.560},{0.390,0.550},{0.390,0.460},{0.400,0.450},{0.400,0.380},{0.410,0.370},{0.410,0.280},{0.420,0.270},{0.420,0.210},{0.430,0.200},{0.430,0.110},{0.440,0.100},{0.440,0.040},{0.430,0.030},{0.370,0.030},{0.360,0.020},{0.270,0.020},{0.260,0.010},{0.190,0.010},{0.180,0.000}};
        float p0008[180][2] = {{0.623,0.000},{0.597,0.026},{0.584,0.026},{0.571,0.039},{0.558,0.039},{0.545,0.052},{0.532,0.052},{0.519,0.065},{0.506,0.065},{0.494,0.078},{0.481,0.078},{0.468,0.091},{0.455,0.091},{0.429,0.117},{0.416,0.117},{0.403,0.130},{0.390,0.130},{0.377,0.143},{0.364,0.143},{0.351,0.156},{0.338,0.156},{0.325,0.169},{0.312,0.169},{0.286,0.195},{0.273,0.195},{0.260,0.208},{0.247,0.208},{0.234,0.221},{0.221,0.221},{0.208,0.234},{0.195,0.234},{0.182,0.247},{0.169,0.247},{0.156,0.260},{0.143,0.260},{0.117,0.286},{0.104,0.286},{0.091,0.299},{0.078,0.299},{0.065,0.312},{0.052,0.312},{0.039,0.325},{0.026,0.325},{0.013,0.338},{0.000,0.338},{0.000,0.351},{0.013,0.364},{0.013,0.377},{0.026,0.390},{0.026,0.403},{0.039,0.416},{0.039,0.429},{0.065,0.455},{0.065,0.468},{0.078,0.481},{0.078,0.494},{0.091,0.506},{0.091,0.519},{0.104,0.532},{0.104,0.545},{0.117,0.558},{0.117,0.571},{0.143,0.597},{0.143,0.610},{0.156,0.623},{0.156,0.636},{0.169,0.649},{0.169,0.662},{0.182,0.675},{0.182,0.688},{0.195,0.701},{0.195,0.714},{0.208,0.727},{0.208,0.740},{0.221,0.753},{0.221,0.766},{0.247,0.792},{0.247,0.805},{0.260,0.818},{0.260,0.831},{0.273,0.844},{0.273,0.857},{0.286,0.870},{0.286,0.883},{0.299,0.896},{0.299,0.909},{0.325,0.935},{0.325,0.948},{0.338,0.961},{0.338,0.974},{0.351,0.987},{0.364,0.974},{0.377,0.974},{0.390,0.961},{0.403,0.961},{0.416,0.948},{0.429,0.948},{0.442,0.935},{0.455,0.935},{0.468,0.922},{0.481,0.922},{0.506,0.896},{0.519,0.896},{0.532,0.883},{0.545,0.883},{0.558,0.870},{0.571,0.870},{0.584,0.857},{0.597,0.857},{0.610,0.844},{0.623,0.844},{0.636,0.831},{0.649,0.831},{0.675,0.805},{0.688,0.805},{0.701,0.792},{0.714,0.792},{0.727,0.779},{0.740,0.779},{0.753,0.766},{0.766,0.766},{0.779,0.753},{0.792,0.753},{0.805,0.740},{0.818,0.740},{0.831,0.727},{0.844,0.727},{0.870,0.701},{0.883,0.701},{0.896,0.688},{0.909,0.688},{0.922,0.675},{0.935,0.675},{0.948,0.662},{0.961,0.662},{0.974,0.649},{0.987,0.649},{0.987,0.623},{0.974,0.610},{0.974,0.597},{0.961,0.584},{0.961,0.571},{0.935,0.545},{0.935,0.532},{0.922,0.519},{0.922,0.506},{0.909,0.494},{0.909,0.481},{0.896,0.468},{0.896,0.455},{0.883,0.442},{0.883,0.429},{0.857,0.403},{0.857,0.390},{0.844,0.377},{0.844,0.364},{0.831,0.351},{0.831,0.338},{0.818,0.325},{0.818,0.312},{0.805,0.299},{0.805,0.286},{0.792,0.273},{0.792,0.260},{0.779,0.247},{0.779,0.234},{0.753,0.208},{0.753,0.182},{0.727,0.156},{0.727,0.143},{0.714,0.130},{0.714,0.117},{0.701,0.104},{0.701,0.091},{0.688,0.078},{0.688,0.065},{0.675,0.052},{0.675,0.039},{0.649,0.013},{0.649,0.000}};
        float p0009[10][2] = {{0.000,0.000},{0.507,0.507},{0.507,0.521},{0.521,0.535},{0.535,0.535},{0.634,0.634},{0.634,0.648},{0.972,0.986},{0.986,0.986},{0.986,0.000}};
        float p0010[87][2] = {{0.375,0.000},{0.357,0.018},{0.321,0.018},{0.304,0.036},{0.286,0.036},{0.268,0.054},{0.250,0.054},{0.232,0.071},{0.214,0.071},{0.161,0.125},{0.143,0.125},{0.143,0.143},{0.071,0.214},{0.071,0.232},{0.054,0.250},{0.054,0.268},{0.036,0.286},{0.036,0.321},{0.018,0.339},{0.018,0.375},{0.000,0.393},{0.000,0.589},{0.018,0.607},{0.018,0.643},{0.036,0.661},{0.036,0.679},{0.054,0.696},{0.054,0.714},{0.071,0.732},{0.071,0.750},{0.107,0.786},{0.107,0.804},{0.179,0.875},{0.196,0.875},{0.232,0.911},{0.250,0.911},{0.268,0.929},{0.286,0.929},{0.304,0.946},{0.339,0.946},{0.357,0.964},{0.429,0.964},{0.446,0.982},{0.554,0.982},{0.571,0.964},{0.625,0.964},{0.643,0.946},{0.679,0.946},{0.696,0.929},{0.714,0.929},{0.732,0.911},{0.750,0.911},{0.786,0.875},{0.804,0.875},{0.875,0.804},{0.875,0.786},{0.911,0.750},{0.911,0.732},{0.929,0.714},{0.929,0.696},{0.946,0.679},{0.946,0.661},{0.964,0.643},{0.964,0.607},{0.982,0.589},{0.982,0.393},{0.964,0.375},{0.964,0.339},{0.946,0.321},{0.946,0.286},{0.929,0.268},{0.929,0.250},{0.911,0.232},{0.911,0.214},{0.857,0.161},{0.857,0.143},{0.839,0.125},{0.821,0.125},{0.768,0.071},{0.750,0.071},{0.732,0.054},{0.714,0.054},{0.696,0.036},{0.679,0.036},{0.661,0.018},{0.625,0.018},{0.607,0.000}};
        float p0011[95][2] = {{0.324,0.000},{0.324,0.014},{0.310,0.028},{0.310,0.056},{0.296,0.070},{0.296,0.099},{0.282,0.113},{0.282,0.141},{0.268,0.155},{0.268,0.183},{0.254,0.197},{0.254,0.225},{0.239,0.239},{0.239,0.268},{0.225,0.282},{0.225,0.310},{0.211,0.324},{0.211,0.352},{0.197,0.366},{0.197,0.394},{0.183,0.408},{0.183,0.437},{0.169,0.451},{0.169,0.479},{0.155,0.493},{0.155,0.521},{0.141,0.535},{0.141,0.563},{0.127,0.577},{0.127,0.606},{0.113,0.620},{0.113,0.648},{0.099,0.662},{0.099,0.690},{0.085,0.704},{0.085,0.732},{0.070,0.746},{0.070,0.775},{0.056,0.789},{0.056,0.817},{0.042,0.831},{0.042,0.859},{0.028,0.873},{0.028,0.901},{0.014,0.915},{0.014,0.944},{0.000,0.958},{0.000,0.986},{0.648,0.986},{0.648,0.944},{0.634,0.930},{0.634,0.901},{0.620,0.887},{0.620,0.859},{0.606,0.845},{0.606,0.817},{0.592,0.803},{0.592,0.775},{0.577,0.761},{0.577,0.732},{0.563,0.718},{0.563,0.690},{0.549,0.676},{0.549,0.648},{0.535,0.634},{0.535,0.606},{0.521,0.592},{0.521,0.563},{0.507,0.549},{0.507,0.521},{0.493,0.507},{0.493,0.479},{0.479,0.465},{0.479,0.437},{0.465,0.423},{0.465,0.394},{0.451,0.380},{0.451,0.352},{0.437,0.338},{0.437,0.324},{0.423,0.310},{0.423,0.268},{0.408,0.254},{0.408,0.239},{0.394,0.225},{0.394,0.197},{0.380,0.183},{0.380,0.155},{0.366,0.141},{0.366,0.113},{0.352,0.099},{0.352,0.070},{0.338,0.056},{0.338,0.028},{0.324,0.014}};//!!//

};
