#include <iostream>
#include <vector>
#include <utility>

template<typename T>
class matrix {
private:
	int m_width;
	int m_height;
	std::vector<T> m_data;
public:
	matrix(int width, int height) : m_width(width), m_height(height) {
		m_data.resize(width * height);
	}	
	~matrix() {};
	const int width() const { return m_width; };
	const int height() const { return m_height; };
	T &operator[](std::pair<int, int> coordinate) {
       		return m_data[coordinate.second * m_width + coordinate.first];
	}
};

int main(int argc, char *argv[]) {
	const int WIDTH  = 10;
	const int HEIGHT = 10;
	matrix<char> a(WIDTH, HEIGHT);
	
	for (int y = 0; y < HEIGHT; ++y)
	       	for (int x = 0; x < WIDTH; ++x) a[{x, y}] = 0;

	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int px, py, r;
		std::cin >> px >> py >> r;
		int ly = std::max(py - r, 0);
		int uy = std::min(py + r + 1, HEIGHT);
		for (int y = ly; y < uy; ++y) {
			int lx = std::max(px - r, 0);
			int ux = std::min(px + r + 1, WIDTH);
			for (int x = lx; x < ux; ++x) {
				int dx = x - px;
				int dy = y - py;
				if (dx * dx + dy * dy <= r * r) a[{x, y}] = 1;
			}
		}
	}

	return 0;
}
