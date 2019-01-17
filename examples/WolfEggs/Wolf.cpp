#include "Wolf.h"

volatile uint8_t Wolf::basket_position = 0;
volatile uint8_t Wolf::wolf_position = 0;

Wolf::Wolf(){
    // Basket
    this->basketUpRight_x0 = this->wolfRight_x0 + this->wolf_columns - 9;
    this->basketUpRight_y0 = this->wolfRight_y0;
    this->basketUpLeft_x0 = this->wolfLeft_x0 - this->basketUp_columns + 9;
    this->basketUpLeft_y0 = this->wolfLeft_y0;
    this->basketDownRight_x0 = this->wolfRight_x0 + this->wolf_columns - 7;
    this->basketDownRight_y0 = this->wolfRight_y0 + this->wolf_raws - this->basketDown_raws;
    this->basketDownLeft_x0 = this->wolfLeft_x0 - this->basketDown_columns + 7;
    this->basketDownLeft_y0 = this->wolfRight_y0 + this->wolf_raws - this->basketDown_raws;
}

void Wolf::wolfRightAppear(){
    Drawer::instance().castSelectedRangeCustom(
        this->wolfRight_x0,
        this->wolfRight_y0,
        this->wolfRight_x0 + this->wolf_columns - 1,
        this->wolfRight_y0 + this->wolf_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        RIGHT,
        wolf_right_map,
        this->wolf_raws,
        this->wolf_columns
    );
}

void Wolf::wolfLeftAppear(){
    Drawer::instance().castSelectedRangeCustom(
        this->wolfLeft_x0,
        this->wolfLeft_y0,
        this->wolfLeft_x0 + this->wolf_columns - 1,
        this->wolfLeft_y0 + this->wolf_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        LEFT,
        wolf_right_map,
        this->wolf_raws,
        this->wolf_columns
    );
}

void Wolf::wolfRightDisappear(){
    Drawer::instance().fillRect(
        this->wolfRight_x0,
        this->wolfRight_y0,
        this->wolf_columns,
        this->wolf_raws,
        WHITE
    );
}

void Wolf::wolfLeftDisappear(){
    Drawer::instance().fillRect(
        this->wolfLeft_x0,
        this->wolfLeft_y0,
        this->wolf_columns,
        this->wolf_raws,
        WHITE
    );
}

void Wolf::basketUpRightAppear(){
    Drawer::instance().castSelectedRangeCustom(
        this->basketUpRight_x0,
        this->basketUpRight_y0 + (this->basketUpPart2_raws - this->basketUpPart1_raws),
        this->basketUpRight_x0 + this->basketUpPart1_columns - 1,
        this->basketUpRight_y0 + (this->basketUpPart2_raws - this->basketUpPart1_raws) + this->basketUpPart1_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        RIGHT,
        basket_up_right_map_part1,
        this->basketUpPart1_raws,
        this->basketUpPart1_columns
    );
    Drawer::instance().castSelectedRangeCustom(
        this->basketUpRight_x0 + this->basketUpPart1_columns,
        this->basketUpRight_y0,
        this->basketUpRight_x0 + this->basketUpPart1_columns + this->basketUpPart2_columns - 1,
        this->basketUpRight_y0 + this->basketUpPart2_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        RIGHT,
        basket_up_right_map_part2,
        this->basketUpPart2_raws,
        this->basketUpPart2_columns
    );
}

void Wolf::basketUpRightDisappear(){
    Drawer::instance().fillRect(
        this->basketUpRight_x0,
        this->basketUpRight_y0 + (this->basketUpPart2_raws - this->basketUpPart1_raws),
        this->basketUpPart1_columns,
        this->basketUpPart1_raws,
        WHITE
    );
    Drawer::instance().fillRect(
        this->basketUpRight_x0 + this->basketUpPart1_columns,
        this->basketUpRight_y0,
        this->basketUpPart2_columns,
        this->basketUpPart2_raws,
        WHITE
    );
}

void Wolf::basketUpLeftAppear(){
    Drawer::instance().castSelectedRangeCustom(
        this->basketUpLeft_x0 + this->basketUpPart2_columns,
        this->basketUpLeft_y0 + (this->basketUpPart2_raws - this->basketUpPart1_raws),
        this->basketUpLeft_x0 + this->basketUpPart2_columns + this->basketUpPart1_columns - 1,
        this->basketUpLeft_y0 + (this->basketUpPart2_raws - this->basketUpPart1_raws) + this->basketUpPart1_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        LEFT,
        basket_up_right_map_part1,
        this->basketUpPart1_raws,
        this->basketUpPart1_columns
    );
    Drawer::instance().castSelectedRangeCustom(
        this->basketUpLeft_x0,
        this->basketUpLeft_y0,
        this->basketUpLeft_x0 + this->basketUpPart2_columns - 1,
        this->basketUpLeft_y0 + this->basketUpPart2_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        LEFT,
        basket_up_right_map_part2,
        this->basketUpPart2_raws,
        this->basketUpPart2_columns
    );
}

void Wolf::basketUpLeftDisappear(){
    Drawer::instance().fillRect(
        this->basketUpLeft_x0 + this->basketUpPart2_columns,
        this->basketUpLeft_y0 + (this->basketUpPart2_raws - this->basketUpPart1_raws),
        this->basketUpPart1_columns,
        this->basketUpPart1_raws,
        WHITE
    );
    Drawer::instance().fillRect(
        this->basketUpLeft_x0,
        this->basketUpLeft_y0,
        this->basketUpPart2_columns,
        this->basketUpPart2_raws,
        WHITE
    );
}

void Wolf::basketDownRightAppear(){
    Drawer::instance().castSelectedRangeCustom(
        this->basketDownRight_x0,
        this->basketDownRight_y0,
        this->basketDownRight_x0 + this->basketDownPart1_columns - 1,
        this->basketDownRight_y0 + this->basketDownPart1_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        RIGHT,
        basket_down_right_map_part1,
        this->basketDownPart1_raws,
        this->basketDownPart1_columns
    );
    Drawer::instance().castSelectedRangeCustom(
        this->basketDownRight_x0 + this->basketDownPart1_columns,
        this->basketDownRight_y0,
        this->basketDownRight_x0 + this->basketDownPart1_columns + this->basketDownPart2_columns - 1,
        this->basketDownRight_y0 + this->basketDownPart2_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        RIGHT,
        basket_down_right_map_part2,
        this->basketDownPart2_raws,
        this->basketDownPart2_columns
    );
}

void Wolf::basketDownRightDisappear(){
    Drawer::instance().fillRect(
        this->basketDownRight_x0,
        this->basketDownRight_y0,
        this->basketDownPart1_columns,
        this->basketDownPart1_raws,
        WHITE
    );
    Drawer::instance().fillRect(
        this->basketDownRight_x0 + this->basketDownPart1_columns,
        this->basketDownRight_y0,
        this->basketDownPart2_columns,
        this->basketDownPart2_raws,
        WHITE
    );
}

void Wolf::basketDownLeftAppear(){
    Drawer::instance().castSelectedRangeCustom(
        this->basketDownLeft_x0 + this->basketDownPart2_columns,
        this->basketDownLeft_y0,
        this->basketDownLeft_x0 + this->basketDownPart2_columns + this->basketDownPart1_columns - 1,
        this->basketDownLeft_y0 + this->basketDownPart1_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        LEFT,
        basket_down_right_map_part1,
        this->basketDownPart1_raws,
        this->basketDownPart1_columns
    );
    Drawer::instance().castSelectedRangeCustom(
        this->basketDownLeft_x0,
        this->basketDownLeft_y0,
        this->basketDownLeft_x0 + this->basketDownPart2_columns - 1,
        this->basketDownLeft_y0 + this->basketDownPart2_raws - 1
    );
    Drawer::instance().writeMemoryCustom(
        LEFT,
        basket_down_right_map_part2,
        this->basketDownPart2_raws,
        this->basketDownPart2_columns
    );
}

void Wolf::basketDownLeftDisappear(){
    Drawer::instance().fillRect(
        this->basketDownLeft_x0 + this->basketDownPart2_columns,
        this->basketDownLeft_y0,
        this->basketDownPart1_columns,
        this->basketDownPart1_raws,
        WHITE
    );
    Drawer::instance().fillRect(
        this->basketDownLeft_x0,
        this->basketDownLeft_y0,
        this->basketDownPart2_columns,
        this->basketDownPart2_raws,
        WHITE
    );
}
