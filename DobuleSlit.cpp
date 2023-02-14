#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <random>
#include <exception>

// Define the number of photons and the width of the slits
const int num_photons = 1000;
const double slit_width = 0.05;

// Define a structure to store the position and intensity of each photon
struct Photon {
  double x, y;
  double intensity;
};

int main() {
  try {
    // Initialize the random number generator
    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> dist(-slit_width/2.0, slit_width/2.0);

    // Initialize the vector of photons
    std::vector<Photon> photons;

    // Generate the photons
    for (int i = 0; i < num_photons; i++) {
      // Generate a random position for the photon
      double x = dist(rng);
      double y = dist(rng);
      
      // Limit the range of x and y values to ensure the results are accurate
      if (std::abs(x) > slit_width/2.0 || std::abs(y) > slit_width/2.0) {
        continue;
      }

      // Calculate the intensity of the photon using the Fraunhofer diffraction formula
      double intensity = (sin(x * M_PI / slit_width) * sin(y * M_PI / slit_width)) / (x * M_PI / slit_width) / (y * M_PI / slit_width);

      // Add the photon to the vector
      photons.push_back({x, y, intensity});
    }

    // Write the photons to a file
    std::ofstream ofs("photons.txt");
    for (const auto &photon : photons) {
      ofs << photon.x << ' ' << photon.y << ' ' << photon.intensity << '\n';
    }

    // Close the file
    ofs.close();
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
