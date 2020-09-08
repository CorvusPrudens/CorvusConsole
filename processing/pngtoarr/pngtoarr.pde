int test = 0;
float tick = 0;

void setup(){
  //process("tt.png", 32, 4, 4, 6, 3, 6, true);
  //process("bigsheet.png", 1, 7, 16, 20, 16, 16);
  process("running.png", 4, 4, 16, 16, 16, 16, false);
  //process("iconsLarge.png", 21, 21, 24, 24, 16, 16, false);
  //process("TREE.png", 1, 1, 1, 1, 113, 64, false);
  //process("moon.png", 1, 1, 1, 1, 30, 30, false);
 // process("niceTileset.gif", 16, 16, 12, 20, 24, 24, 16, 16, false);
  //process("block.png", 1, 1, 1, 1, 14, 14, false);
  //process("column.png", 1, 1, 1, 1, 39, 63, false);
  //process("torches.png", 3, 1, 6, 1, 6, 22, false);
  writeToFile("output.txt", 16, 16, 4);
  //for (int i = 0; i < 5; i++){
  //  println((chars[test][0] >> i) & 1, (chars[test][1] >> i) & 1, (chars[test][2] >> i) & 1);
  //}
  //println(chars[65]);
  size(600, 600);
  noSmooth();
  //testimg = createImage(32, 32, RGB);
  testimg = displayBitmap(chars[4], 16, 16, 0);
  frameRate(60);
}

void draw(){
  tick += 0.2;
  image(testimg, 0, 0, width, height);
  testimg = displayBitmap(chars[int(tick) % (chars.length)], 16, 16, 0);
}
