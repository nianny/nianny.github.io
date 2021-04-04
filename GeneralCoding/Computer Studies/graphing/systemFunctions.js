function windowResized() {
    resizeCanvas(windowWidth, windowHeight)
    size = min(width, height);
    setUp();
    changeChoice();
  }