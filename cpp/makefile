CXX = g++
MKDIR = mkdir
TARGET = leetcode_solution
OBJ = main.o
OBJ_DIR = ./obj
WARNING_FLAGS = -Wall -Waddress -Warray-bounds -Wc++0x-compat -Wchar-subscripts \
                -Wcomment -Wformat -Wmain -Wmissing-braces -Wnonnull -Wparentheses \
		        -Wreorder -Wreturn-type -Wsequence-point \
                -Wsign-compare -Wstrict-aliasing -Wstrict-overflow=1 \
                -Wswitch -Wtrigraphs -Wuninitialized \
                -Wunknown-pragmas -Wunused-function -Wunused-label -Wunused-value \
                -Wunused-variable

CXXFLAGS = -c $(WARNING_FLAGS) -std=c++11

vpath %.o $(OBJ_DIR)

$(TARGET): $(OBJ)
	$(CXX) $(addprefix $(OBJ_DIR)/, $^) -o $@

%.o:%.cpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) $< -o $(OBJ_DIR)/$@
	
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

.PHONY: clean
clean:
	$(RM) $(OBJ_DIR)/*.o $(TARGET)
