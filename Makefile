# 定义编译器和编译选项
CC = g++
CFLAGS = -Wall -Wextra -std=c++2a -O2 -DNDEBUG -Wno-unused-parameter
CPYFLAGS = $(CFLAGS) -shared

# 项目名称
TARGET = HonestyChecker
SO_TARGET = libHonestyChecker.so

# 目录
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
DIST_DIR = dist
INCLUDE_DIRS = $(shell find $(INCLUDE_DIR) -type d -exec echo -I{} \;) -I /usr/include/python3.8

$(shell mkdir -p $(OBJ_DIR) $(DIST_DIR))

# 查找所有源文件
SRCS = $(shell find $(SRC_DIR) -name "*.cpp" -not -path "src/interface/*")
SRCS_ALL = $(shell find $(SRC_DIR) -name "*.cpp")

# 生成对象文件名
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_ALL = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS_ALL))

# default
.PHONY: all
all:
	@echo "Usage: make [normal|python|clean]"

# 清理
.PHONY: clean
clean:
	rm -rf $(DIST_DIR) $(OBJ_DIR) 

# what's we want when executing "make normal"
.PHONY: normal
normal: $(DIST_DIR)/$(TARGET)

# what's we want when executing "make python"
.PHONY: python
python: $(DIST_DIR)/$(SO_TARGET)

# make normal
$(DIST_DIR)/$(TARGET): $(OBJS) $(OBJ_DIR)/interface/normal_interface.o
	$(CC) $(CFLAGS) -o $@ $^

# make python
$(DIST_DIR)/$(SO_TARGET): $(OBJS) $(OBJ_DIR)/interface/python_interface.o
	$(CC) $(CPYFLAGS) -o $@ -fPIC $^

# 编译每个源文件
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -fPIC $(INCLUDE_DIRS) -c $< -o $@ 
