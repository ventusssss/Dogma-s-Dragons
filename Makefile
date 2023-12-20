PROJECT_NAME = ddgm
BUILD_DIR = build
TARGET = $(BUILD_DIR)/$(PROJECT_NAME)
SRC = $(wildcard src/*.cpp)
CXX_FLAGS = -Iinclude -O2 -std=c++17

$(TARGET): $(SRC)
	@ mkdir -p $(BUILD_DIR)
	$(CXX) -o $@ $^ $(CXX_FLAGS)

run: $(TARGET)
	./$^