INCLUDE = ./include
SRC = ./src
BUILD = ./build
EXP = ./testcode

app:$(BUILD)/MLP.o \
	$(BUILD)/CNN.o \
	$(BUILD)/Tools.o \
	$(EXP)/exp1.cpp
	g++ -I$(INCLUDE) $^ -o $@

$(BUILD)/%.o:$(SRC)/%.cpp
	g++ -I$(INCLUDE) -c $< -o $@

clean:
	rm -rf $(BUILD)
	mkdir $(BUILD)
