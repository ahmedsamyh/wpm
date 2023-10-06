#include <MoGE/MoGE.hpp>
#include <MoUI/MoUI.hpp>
#include <format>
#include <fstream>

using namespace momo;

#define S_WIDTH 1280
#define S_HEIGHT 720
#define WIDTH S_WIDTH / 1.5
#define HEIGHT S_HEIGHT / 1.5

#define KEY_SIZE 32
#define UPPER_PAD (KEY_SIZE * 0.25)
#define KEY_PAD (KEY_SIZE * 0.05)

#define TAB_SIZE (KEY_SIZE * 1.5f)
#define CAPS_SIZE (KEY_SIZE * 1.75f)
#define SHIFT_SIZE (KEY_SIZE * 2.05f)
#define RSHIFT_SIZE (KEY_SIZE * 2.95f)
#define SPACE_SIZE (KEY_SIZE * 6.f)
#define BOTTOM_KEY_SIZE (KEY_SIZE * 1.28f)
#define BACKSLASH_SIZE TAB_SIZE
#define ENTER_SIZE (KEY_SIZE * 2.25f)
#define BACKSPACE_SIZE (KEY_SIZE * 2.f)

static Vec2 keyboardPos = {16.f, 264.f};

#define NUM_X                                                                  \
  ((BOTTOM_KEY_SIZE * 3) + SPACE_SIZE + (BOTTOM_KEY_SIZE * 4) + UPPER_PAD +    \
   (KEY_SIZE * 3) + UPPER_PAD)
void drawKeyEx(size_t key, const Vec2 _pos, const float width,
               const std::string &keyStr, const int charSize = -1) {
  Vec2 pos = _pos;
  solidRect(pos, {width, KEY_SIZE},
            (keyHeld(key) ? Color(255, 255, 255, 100) : Color(0, 0, 0, 0)));
  drawRect(pos, {width, KEY_SIZE});
  pushAlign();
  setTextAlign(VA::Center, HA::Center);
  drawText(pos + Vec2(width / 2.f, KEY_SIZE / 2.f), keyStr,
           (charSize == -1 ? KEY_SIZE / 2 : charSize));
  popAlign();
}

void drawKey(size_t key, const Vec2 _pos, const std::string &keyStr,
             const int charSize = -1) {
  drawKeyEx(key, _pos, KEY_SIZE, keyStr, charSize);
}

void drawKeys(size_t key) {
  switch (key) {
  case A:
    drawKey(A,
            {CAPS_SIZE + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "A");
    break;
  case B:
    drawKey(
        B, {SHIFT_SIZE + (KEY_SIZE * 4), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        "B");
    break;
  case C:
    drawKey(
        C, {SHIFT_SIZE + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        "C");
    break;
  case D:
    drawKey(D,
            {CAPS_SIZE + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "D");
    break;
  case E:
    drawKey(E,
            {TAB_SIZE + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "E");
    break;
  case F:
    drawKey(F,
            {CAPS_SIZE + (KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "F");
    break;
  case G:
    drawKey(G,
            {CAPS_SIZE + (KEY_SIZE * 4), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "G");
    break;
  case H:
    drawKey(H,
            {CAPS_SIZE + (KEY_SIZE * 5), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "H");
    break;
  case I:
    drawKey(I,
            {TAB_SIZE + (KEY_SIZE * 7), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "I");
    break;
  case J:
    drawKey(J,
            {CAPS_SIZE + (KEY_SIZE * 6), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "J");
    break;
  case K:
    drawKey(K,
            {CAPS_SIZE + (KEY_SIZE * 7), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "K");
    break;
  case L:
    drawKey(L,
            {CAPS_SIZE + (KEY_SIZE * 8), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "L");
    break;
  case M:
    drawKey(
        M, {SHIFT_SIZE + (KEY_SIZE * 6), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        "M");
    break;
  case N:
    drawKey(
        N, {SHIFT_SIZE + (KEY_SIZE * 5), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        "N");
    break;
  case O:
    drawKey(O,
            {TAB_SIZE + (KEY_SIZE * 8), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "O");
    break;
  case P:
    drawKey(P,
            {TAB_SIZE + (KEY_SIZE * 9), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "P");
    break;
  case Q:
    drawKey(Q,
            {TAB_SIZE + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "Q");
    break;
  case R:
    drawKey(R,
            {TAB_SIZE + (KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "R");
    break;
  case S:
    drawKey(S,
            {CAPS_SIZE + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "S");
    break;
  case T:
    drawKey(T,
            {TAB_SIZE + (KEY_SIZE * 4), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "T");
    break;
  case U:
    drawKey(U,
            {TAB_SIZE + (KEY_SIZE * 6), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "U");
    break;
  case V:
    drawKey(
        V, {SHIFT_SIZE + (KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        "V");
    break;
  case W:
    drawKey(W,
            {TAB_SIZE + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "W");
    break;
  case X:
    drawKey(
        X, {SHIFT_SIZE + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        "X");
    break;
  case Y:
    drawKey(Y,
            {TAB_SIZE + (KEY_SIZE * 5), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "Y");
    break;
  case Z:
    drawKey(
        Z, {SHIFT_SIZE + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        "Z");
    break;
  case Num0:
    drawKey(Num0, {(KEY_SIZE * 10), KEY_SIZE + UPPER_PAD}, "0");
    break;
  case Num1:
    drawKey(Num1, {(KEY_SIZE * 1), KEY_SIZE + UPPER_PAD}, "1");
    break;
  case Num2:
    drawKey(Num2, {(KEY_SIZE * 2), KEY_SIZE + UPPER_PAD}, "2");
    break;
  case Num3:
    drawKey(Num3, {(KEY_SIZE * 3), KEY_SIZE + UPPER_PAD}, "3");
    break;
  case Num4:
    drawKey(Num4, {(KEY_SIZE * 4), KEY_SIZE + UPPER_PAD}, "4");
    break;
  case Num5:
    drawKey(Num5, {(KEY_SIZE * 5), KEY_SIZE + UPPER_PAD}, "5");
    break;
  case Num6:
    drawKey(Num6, {(KEY_SIZE * 6), KEY_SIZE + UPPER_PAD}, "6");
    break;
  case Num7:
    drawKey(Num7, {(KEY_SIZE * 7), KEY_SIZE + UPPER_PAD}, "7");
    break;
  case Num8:
    drawKey(Num8, {(KEY_SIZE * 8), KEY_SIZE + UPPER_PAD}, "8");
    break;
  case Num9:
    drawKey(Num9, {(KEY_SIZE * 9), KEY_SIZE + UPPER_PAD}, "9");
    break;
  case Escape:
    drawKey(Escape, {0.f, 0.f}, "Esc", 8);
    break;
  case LControl:
    drawKeyEx(LControl, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
              BOTTOM_KEY_SIZE, "Ctrl", 8);
    break;
  case LShift:
    drawKeyEx(LShift, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)}, SHIFT_SIZE,
              "Shift", 8);
    break;
  case LAlt:
    drawKeyEx(LAlt,
              {(BOTTOM_KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
              BOTTOM_KEY_SIZE, "Alt", 8);
    break;
  case LSystem:
    drawKeyEx(LSystem,
              {(BOTTOM_KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
              BOTTOM_KEY_SIZE, "Win", 8);
    break;
  case RControl:
    drawKeyEx(RControl,
              {(BOTTOM_KEY_SIZE * 3) + SPACE_SIZE + (BOTTOM_KEY_SIZE * 3),
               KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
              BOTTOM_KEY_SIZE, "Ctrl", 8);
    break;
  case RShift:
    drawKeyEx(
        RShift,
        {SHIFT_SIZE + (KEY_SIZE * 10), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        RSHIFT_SIZE, "Shift", 8);
    break;
  case RAlt:
    drawKeyEx(RAlt,
              {(BOTTOM_KEY_SIZE * 3) + SPACE_SIZE,
               KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
              BOTTOM_KEY_SIZE, "Alt", 8);
    break;
  case RSystem:
    break;
  case Menu:
    drawKeyEx(Menu,
              {(BOTTOM_KEY_SIZE * 5) + SPACE_SIZE,
               KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
              BOTTOM_KEY_SIZE, "Menu", 8);
    break;
  case LBracket:
    drawKey(LBracket,
            {TAB_SIZE + (KEY_SIZE * 10), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "[");
    break;
  case RBracket:
    drawKey(RBracket,
            {TAB_SIZE + (KEY_SIZE * 11), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "]");
    break;
  case Semicolon:
    drawKey(Semicolon,
            {CAPS_SIZE + (KEY_SIZE * 9), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            ";");
    break;
  case Comma:
    drawKey(
        Comma,
        {SHIFT_SIZE + (KEY_SIZE * 7), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        ",");
    break;
  case Period:
    drawKey(
        Period,
        {SHIFT_SIZE + (KEY_SIZE * 8), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        ".");
    break;
  case Quote:
    drawKey(
        Quote,
        {CAPS_SIZE + (KEY_SIZE * 10), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
        "'");
    break;
  case Slash:
    drawKey(
        Slash,
        {SHIFT_SIZE + (KEY_SIZE * 9), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
        "/");
    break;
  case BackSlash:
    drawKeyEx(
        BackSlash,
        {TAB_SIZE + (KEY_SIZE * 12), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
        BACKSLASH_SIZE, "\\");
    break;
  case Tilde:
    drawKey(Tilde, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 0)}, "`");
    break;
  case Equal:
    drawKey(Equal, {(KEY_SIZE * 12), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 0)},
            "=");
    break;
  case Hyphen:
    drawKey(Hyphen, {(KEY_SIZE * 11), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 0)},
            "-");
    break;
  case Space:
    drawKeyEx(Space,
              {(BOTTOM_KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
              SPACE_SIZE, " ");
    break;
  case Enter:
    drawKeyEx(
        Enter,
        {CAPS_SIZE + (KEY_SIZE * 11), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
        ENTER_SIZE, "Enter", 8);
    break;
  case Backspace:
    drawKeyEx(Backspace,
              {(KEY_SIZE * 13), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 0)},
              BACKSPACE_SIZE, "Bckspc", 8);
    break;
  case Tab:
    drawKeyEx(Tab, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)}, TAB_SIZE,
              "Tab", 8);
    break;
  case PageUp:
  case PageDown:
  case End:
  case Home:
  case Insert:
  case Delete:
  case Add:
  case Subtract:
  case Multiply:
  case Divide:
    break;
  case Left:
    drawKey(Left,
            {NUM_X - UPPER_PAD - (KEY_SIZE * 3),
             KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
            "<-", 8);
    break;
  case Right:
    drawKey(Right,
            {NUM_X - UPPER_PAD - (KEY_SIZE * 1),
             KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
            "->", 8);
    break;
  case Up:
    drawKey(Up,
            {NUM_X - UPPER_PAD - (KEY_SIZE * 2),
             KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
            "^", 8);
    break;
  case Down:
    drawKey(Down,
            {NUM_X - UPPER_PAD - (KEY_SIZE * 2),
             KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
            "v", 8);
    break;
  case KeyCount:
    drawKeyEx(KeyCount, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)}, CAPS_SIZE,
              "Caps", 8);
    break;

  case Numpad0:
    drawKeyEx(Numpad0, {NUM_X, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
              KEY_SIZE * 2, "0");
    break;
  case Numpad1:
    drawKey(Numpad1, {NUM_X, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)}, "1");
    break;
  case Numpad2:
    drawKey(Numpad2,
            {NUM_X + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
            "2");
    break;
  case Numpad3:
    drawKey(Numpad3,
            {NUM_X + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
            "3");
    break;
  case Numpad4:
    drawKey(Numpad4,
            {NUM_X + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "4");
    break;
  case Numpad5:
    drawKey(Numpad5,
            {NUM_X + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "5");
    break;
  case Numpad6:
    drawKey(Numpad6,
            {NUM_X + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
            "6");
    break;
  case Numpad7:
    drawKey(Numpad7,
            {NUM_X + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "7");
    break;
  case Numpad8:
    drawKey(Numpad8,
            {NUM_X + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "8");
    break;
  case Numpad9:
    drawKey(Numpad9,
            {NUM_X + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
            "9");
    break;

  default: {
    // UNREACHABLE();
  } break;
  }
}

void drawKeyboard() {
  setViewPos(keyboardPos);
  for (auto &key : Data::keys) {
    drawKeys(key.keycode);
  }
  defView();
}

struct MainScene : public Scene {
  std::string buffer;
  std::string text;
  UI ui;
  float time_passed = 0.f, time_done = 0.f;
  int character_per_sec = 0;
  bool done = false;
  MainScene() {
    ///
    id = 0;
  }

  void init() override {
    ///
    std::ifstream ifs;
    ifs.open("input.txt");

    if (ifs.is_open()) {

      ifs >> text;

      ifs.close();
    }
  }

  void input() override {
    char key = getCharEntered();
    if (key != -1 && key != 8 && key != '\r') {
      buffer += (char)key;
    }
    if (keyPressed(Escape)) {
      buffer.pop_back();
    }

    if (buffer.size() > 0 && keyPressed(Backspace)) {
      buffer.pop_back();
    }

    if (buffer.size() > 0 && keyHeld(LControl) && keyHeld(LShift) &&
        keyPressed(Backspace)) {
      buffer.clear();
    }
  }

  void update(float delta) override {
    ///
    if (!done) {
      time_passed += delta;
    }

    if (buffer.starts_with(text)) {
      time_done = time_passed;
      done = true;
    }

    character_per_sec = buffer.size() / time_passed;
  }

  void draw() override {
    ///
    drawKeyboard();

    { // view
      drawText({AW / 2.f, 0.f}, std::format("time: {}s", time_passed),
               KEY_SIZE / 2);

      drawText({AW / 2.f, KEY_SIZE / 2},
               std::format("ch/s: {}", character_per_sec), KEY_SIZE / 2);

      setViewPos({16.f, 16.f});
      drawText({0.f, 0.f}, text, KEY_SIZE / 2, Color(255, 255, 255, 100));

      for (size_t i = 0; i < buffer.size(); ++i) {
        char ch = buffer[i];
        Color col = WHITE;
        if (!text.empty() && i < text.size()) {
          if (ch != text[i]) {
            col = RED;
          }
        }
        drawText({float(i * KEY_SIZE / 2), 0.f}, std::string{ch}, KEY_SIZE / 2,
                 col);
      }

      defView();
    }
  }
};

int main(int argc, char *argv[]) {
  MAIN(MainScene);
  create("wpm", S_WIDTH, S_HEIGHT, WIDTH, HEIGHT);
  run();
  return 0;
}
