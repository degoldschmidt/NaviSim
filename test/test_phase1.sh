cd ..
g++ test/test_phase1.cpp src/agent.cpp src/environment.cpp src/simulation.cpp src/controller.cpp -std=c++11 -o phase1_test -O1 -larmadillo
./phase1_test
cd data/scripts
gnuplot track-x11.plot