const double FIELD_WIDTH = 20.0;
const double FIELD_HEIGHT = 10.0;
const double SQUARE_WIDTH = 2.0;
const double SQUARE_HEIGHT = 1.0;
const double SUB_WIDTH = 0.0833333333333333;
const double SUB_HEIGHT = 0.0416666666666667;
const double SUB_SUB_WIDTH = 0.0083333333333333;
const double SUB_SUB_HEIGHT = 0.0041666666666667;

char *deg_to_grid(float lat, float lon) // Returns Maidenhead Locator

{
char buff[10];

char *locator;
float latitude = lat;
float longitude = lon;
sprintf(grid,"AA00AA00");

latitude += 90.0;
longitude += 180.0;

char ilong = char(longitude / FIELD_WIDTH);
grid[0] += ilong;
longitude -= double(ilong) * FIELD_WIDTH;

char ilat = char(latitude / FIELD_HEIGHT);
grid[1] += ilat;
latitude -= double(ilat) * FIELD_HEIGHT;

ilong = char(longitude / SQUARE_WIDTH);
grid[2] += ilong;
longitude -= double(ilong) * SQUARE_WIDTH;

ilat = char(latitude / SQUARE_HEIGHT);
grid[3] += ilat;
latitude -= double(ilat) * SQUARE_HEIGHT;

ilong = char(longitude / SUB_WIDTH);
grid[4] += ilong;
longitude -= double(ilong) * SUB_WIDTH;

ilat = char(latitude / SUB_HEIGHT);
grid[5] += ilat;
latitude -= double(ilat) * SUB_HEIGHT;

//ilong = char(longitude / SUB_SUB_WIDTH);
//grid[6] += ilong;

//ilat = char(latitude / SUB_SUB_HEIGHT);
//grid[7] += ilat;
grid[6]=0;
grid[7]=0;
grid[8]=0;
grid[9]=0;

#ifdef DEBUG
Serial.print("\nGrid = ");
Serial.print(grid);
Serial.print("\n");
#endif
return *grid;
}
