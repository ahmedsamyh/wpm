#define SFML_HELPER_IMPLEMENTATION
#include <sfml-helper.hpp>

using namespace sh;

#define KEY_SIZE 48.f
#define UPPER_PAD (KEY_SIZE * 0.25f)
#define KEY_PAD (KEY_SIZE * 0.05f)

#define TAB_SIZE (KEY_SIZE * 1.5f)
#define CAPS_SIZE (KEY_SIZE * 1.75f)
#define SHIFT_SIZE (KEY_SIZE * 2.05f)
#define RSHIFT_SIZE (KEY_SIZE * 2.95f)
#define SPACE_SIZE (KEY_SIZE * 6.f)
#define BOTTOM_KEY_SIZE (KEY_SIZE * 1.28f)
#define BACKSLASH_SIZE TAB_SIZE
#define ENTER_SIZE (KEY_SIZE * 2.25f)
#define BACKSPACE_SIZE (KEY_SIZE * 2.f)

#define NUM_X                                                                  \
  ((BOTTOM_KEY_SIZE * 3) + SPACE_SIZE + (BOTTOM_KEY_SIZE * 4) + UPPER_PAD +    \
   (KEY_SIZE * 3) + UPPER_PAD)


// TODO: Maybe move the trim functions to stdcpp
std::string& trim_right(std::string& str){
  while (!str.empty() && std::isspace(str.back())){
    str.pop_back();
  }
  return str;
}

std::string& trim_left(std::string& str){
  while (!str.empty() && std::isspace(str[0])){
    str = str.substr(1);
  }
  return str;
}

std::string& trim(std::string& str){return trim_right(trim_left(str)); }

int main(int argc, char *argv[]) {
  Data d;
  d.init(1280, 720, 1, "wpm");

  std::string buffer{};
  std::string text{"TEXT"};
  UI ui(d);
  float time_passed{0.f}, time_done{0.f};
  float character_per_sec{0.f};
  bool done{false};

  // read text from `input.txt`
  std::ifstream ifs;
  ifs.open("input.txt", std::ios::in);
  if (!ifs.is_open()){
    ERR("Could not open file...\n");
  }

  ifs.seekg(0, std::ios::end);
  text.resize(int(ifs.tellg()) - 2);
  ifs.seekg(0, std::ios::beg);
  
  ifs.read((char*)text.c_str(), text.size());
  
  ifs.close();

  trim(text);

  auto  draw_key_ex = [&](Key key, sf::Vector2f pos, float width,
               const std::string &keyStr, const int charSize = -1) {
    d.draw_rect(pos, sf::Vector2f{width, KEY_SIZE}, TopLeft,
		(d.k_held(key) ? sf::Color{255, 255, 255, 100} : sf::Color{0, 0, 0, 0}));
	      // drawRect(pos, {width, KEY_SIZE});
	      // d.draw_text(pos + Vec2(width / 2.f, KEY_SIZE / 2.f), keyStr,
	      // (charSize == -1 ? KEY_SIZE / 2 : charSize));
  };

  auto draw_key = [&](Key key, sf::Vector2f pos, const std::string &key_str,
             const int charSize = -1) {
    draw_key_ex(key, pos, KEY_SIZE, key_str, charSize);
  };

  auto draw_keys = [&](Key key) {
    switch (key) {
    case Key::A:
      draw_key(Key::A,
	      {CAPS_SIZE + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "A");
      break;
    case Key::B:
      draw_key(Key::B, {SHIFT_SIZE + (KEY_SIZE * 4), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "B");
      break;
    case Key::C:
      draw_key(Key::C, {SHIFT_SIZE + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "C");
      break;
    case Key::D:
      draw_key(Key::D,
	      {CAPS_SIZE + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "D");
      break;
    case Key::E:
      draw_key(Key::E,
	      {TAB_SIZE + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "E");
      break;
    case Key::F:
      draw_key(Key::F,
	      {CAPS_SIZE + (KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "F");
      break;
    case Key::G:
      draw_key(Key::G,
	      {CAPS_SIZE + (KEY_SIZE * 4), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "G");
      break;
    case Key::H:
      draw_key(Key::H,
	      {CAPS_SIZE + (KEY_SIZE * 5), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "H");
      break;
    case Key::I:
      draw_key(Key::I,
	      {TAB_SIZE + (KEY_SIZE * 7), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "I");
      break;
    case Key::J:
      draw_key(Key::J,
	      {CAPS_SIZE + (KEY_SIZE * 6), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "J");
      break;
    case Key::K:
      draw_key(Key::K,
	      {CAPS_SIZE + (KEY_SIZE * 7), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "K");
      break;
    case Key::L:
      draw_key(Key::L,
	      {CAPS_SIZE + (KEY_SIZE * 8), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "L");
      break;
    case Key::M:
      draw_key(Key::M, {SHIFT_SIZE + (KEY_SIZE * 6), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "M");
      break;
    case Key::N:
      draw_key(Key::N, {SHIFT_SIZE + (KEY_SIZE * 5), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "N");
      break;
    case Key::O:
      draw_key(Key::O,
	      {TAB_SIZE + (KEY_SIZE * 8), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "O");
      break;
    case Key::P:
      draw_key(Key::P,
	      {TAB_SIZE + (KEY_SIZE * 9), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "P");
      break;
    case Key::Q:
      draw_key(Key::Q,
	      {TAB_SIZE + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "Q");
      break;
    case Key::R:
      draw_key(Key::R,
	      {TAB_SIZE + (KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "R");
      break;
    case Key::S:
      draw_key(Key::S,
	      {CAPS_SIZE + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "S");
      break;
    case Key::T:
      draw_key(Key::T,
	      {TAB_SIZE + (KEY_SIZE * 4), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "T");
      break;
    case Key::U:
      draw_key(Key::U,
	      {TAB_SIZE + (KEY_SIZE * 6), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "U");
      break;
    case Key::V:
      draw_key(Key::V, {SHIFT_SIZE + (KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "V");
      break;
    case Key::W:
      draw_key(Key::W,
	      {TAB_SIZE + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "W");
      break;
    case Key::X:
      draw_key(Key::X, {SHIFT_SIZE + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "X");
      break;
    case Key::Y:
      draw_key(Key::Y,
	      {TAB_SIZE + (KEY_SIZE * 5), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "Y");
      break;
    case Key::Z:
      draw_key(Key::Z, {SHIFT_SIZE + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "Z");
      break;
    case Key::Num0:
      draw_key(Key::Num0, {(KEY_SIZE * 10), KEY_SIZE + UPPER_PAD}, "0");
      break;
    case Key::Num1:
      draw_key(Key::Num1, {(KEY_SIZE * 1), KEY_SIZE + UPPER_PAD}, "1");
      break;
    case Key::Num2:
      draw_key(Key::Num2, {(KEY_SIZE * 2), KEY_SIZE + UPPER_PAD}, "2");
      break;
    case Key::Num3:
      draw_key(Key::Num3, {(KEY_SIZE * 3), KEY_SIZE + UPPER_PAD}, "3");
      break;
    case Key::Num4:
      draw_key(Key::Num4, {(KEY_SIZE * 4), KEY_SIZE + UPPER_PAD}, "4");
      break;
    case Key::Num5:
      draw_key(Key::Num5, {(KEY_SIZE * 5), KEY_SIZE + UPPER_PAD}, "5");
      break;
    case Key::Num6:
      draw_key(Key::Num6, {(KEY_SIZE * 6), KEY_SIZE + UPPER_PAD}, "6");
      break;
    case Key::Num7:
      draw_key(Key::Num7, {(KEY_SIZE * 7), KEY_SIZE + UPPER_PAD}, "7");
      break;
    case Key::Num8:
      draw_key(Key::Num8, {(KEY_SIZE * 8), KEY_SIZE + UPPER_PAD}, "8");
      break;
    case Key::Num9:
      draw_key(Key::Num9, {(KEY_SIZE * 9), KEY_SIZE + UPPER_PAD}, "9");
      break;
    case Key::Escape:
      draw_key(Key::Escape, {0.f, 0.f}, "Esc", 8);
      break;
    case Key::LControl:
      draw_key_ex(Key::LControl, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
		BOTTOM_KEY_SIZE, "Ctrl", 8);
      break;
    case Key::LShift:
      draw_key_ex(Key::LShift, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)}, SHIFT_SIZE,
		"Shift", 8);
      break;
    case Key::LAlt:
      draw_key_ex(Key::LAlt,
		{(BOTTOM_KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
		BOTTOM_KEY_SIZE, "Alt", 8);
      break;
    case Key::LSystem:
      draw_key_ex(Key::LSystem,
		{(BOTTOM_KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
		BOTTOM_KEY_SIZE, "Win", 8);
      break;
    case Key::RControl:
      draw_key_ex(Key::RControl, {(BOTTOM_KEY_SIZE * 3) + SPACE_SIZE + (BOTTOM_KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
		BOTTOM_KEY_SIZE, "Ctrl", 8);
      break;
    case Key::RShift:
      draw_key_ex(Key::RShift, {SHIFT_SIZE + (KEY_SIZE * 10), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)}, RSHIFT_SIZE, "Shift", 8);
      break;
    case Key::RAlt:
      draw_key_ex(Key::RAlt,
		{(BOTTOM_KEY_SIZE * 3) + SPACE_SIZE,
		 KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
		BOTTOM_KEY_SIZE, "Alt", 8);
      break;
    case Key::RSystem:
      break;
    case Key::Menu:
      draw_key_ex(Key::Menu,
		{(BOTTOM_KEY_SIZE * 5) + SPACE_SIZE,
		 KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
		BOTTOM_KEY_SIZE, "Menu", 8);
      break;
    case Key::LBracket:
      draw_key(Key::LBracket,
	      {TAB_SIZE + (KEY_SIZE * 10), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "[");
      break;
    case Key::RBracket:
      draw_key(Key::RBracket,
	      {TAB_SIZE + (KEY_SIZE * 11), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "]");
      break;
    case Key::Semicolon:
      draw_key(Key::Semicolon,
	      {CAPS_SIZE + (KEY_SIZE * 9), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      ";");
      break;
    case Key::Comma:
      draw_key(Key::Comma,
	      {SHIFT_SIZE + (KEY_SIZE * 7), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      ",");
      break;
    case Key::Period:
      draw_key(Key::Period,
	      {SHIFT_SIZE + (KEY_SIZE * 8), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      ".");
      break;
    case Key::Quote:
      draw_key(Key::Quote,
	      {CAPS_SIZE + (KEY_SIZE * 10), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "'");
      break;
    case Key::Slash:
      draw_key(Key::Slash,
	      {SHIFT_SIZE + (KEY_SIZE * 9), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "/");
      break;
    case Key::BackSlash:
      draw_key_ex(Key::BackSlash,
		{TAB_SIZE + (KEY_SIZE * 12), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
		BACKSLASH_SIZE, "\\");
      break;
    case Key::Tilde:
      draw_key(Key::Tilde, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 0)}, "`");
      break;
    case Key::Equal:
      draw_key(Key::Equal, {(KEY_SIZE * 12), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 0)},
	      "=");
      break;
    case Key::Hyphen:
      draw_key(Key::Hyphen, {(KEY_SIZE * 11), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 0)},
	      "-");
      break;
    case Key::Space:
      draw_key_ex(Key::Space,
		{(BOTTOM_KEY_SIZE * 3), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
		SPACE_SIZE, " ");
      break;
    case Key::Enter:
      draw_key_ex(Key::Enter,
		{CAPS_SIZE + (KEY_SIZE * 11), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
		ENTER_SIZE, "Enter", 8);
      break;
    case Key::Backspace:
      draw_key_ex(Key::Backspace,
		{(KEY_SIZE * 13), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 0)},
		BACKSPACE_SIZE, "Bckspc", 8);
      break;
    case Key::Tab:
      draw_key_ex(Key::Tab, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)}, TAB_SIZE,
		"Tab", 8);
      break;
    case Key::PageUp:
    case Key::PageDown:
    case Key::End:
    case Key::Home:
    case Key::Insert:
    case Key::Delete:
    case Key::Add:
    case Key::Subtract:
    case Key::Multiply:
    case Key::Divide:
      break;
    case Key::Left:
      draw_key(Key::Left,
	      {NUM_X - UPPER_PAD - (KEY_SIZE * 3),
	       KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
	      "<-", 8);
      break;
    case Key::Right:
      draw_key(Key::Right,
	      {NUM_X - UPPER_PAD - (KEY_SIZE * 1),
	       KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
	      "->", 8);
      break;
    case Key::Up:
      draw_key(Key::Up,
	      {NUM_X - UPPER_PAD - (KEY_SIZE * 2),
	       KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "^", 8);
      break;
    case Key::Down:
      draw_key(Key::Down,
	      {NUM_X - UPPER_PAD - (KEY_SIZE * 2),
	       KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
	      "v", 8);
      break;
    case Key::KeyCount:
      draw_key_ex(Key::KeyCount, {0.f, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)}, CAPS_SIZE,
		"Caps", 8);
      break;

    case Key::Numpad0:
      draw_key_ex(Key::Numpad0, {NUM_X, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 4)},
		KEY_SIZE * 2, "0");
      break;
    case Key::Numpad1:
      draw_key(Key::Numpad1, {NUM_X, KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)}, "1");
      break;
    case Key::Numpad2:
      draw_key(Key::Numpad2,
	      {NUM_X + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "2");
      break;
    case Key::Numpad3:
      draw_key(Key::Numpad3,
	      {NUM_X + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 3)},
	      "3");
      break;
    case Key::Numpad4:
      draw_key(Key::Numpad4,
	      {NUM_X + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "4");
      break;
    case Key::Numpad5:
      draw_key(Key::Numpad5,
	      {NUM_X + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "5");
      break;
    case Key::Numpad6:
      draw_key(Key::Numpad6,
	      {NUM_X + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 2)},
	      "6");
      break;
    case Key::Numpad7:
      draw_key(Key::Numpad7,
	      {NUM_X + (KEY_SIZE * 0), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "7");
      break;
    case Key::Numpad8:
      draw_key(Key::Numpad8,
	      {NUM_X + (KEY_SIZE * 1), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "8");
      break;
    case Key::Numpad9:
      draw_key(Key::Numpad9,
	      {NUM_X + (KEY_SIZE * 2), KEY_SIZE + UPPER_PAD + (KEY_SIZE * 1)},
	      "9");
      break;

    default: {
      // UNREACHABLE();
    } break;
    }
  };

  auto  draw_keyboard = [&]() {
    d.camera_view();
    sf::Vector2f padding{10.f, 35.f};
    d.camera_follow({(d.width/2.f) - padding.x, -padding.y});
    for (size_t i=0; i < int(Key::KeyCount); ++i) {
      draw_keys(Key(i));
    }
    d.default_view();
  };
  
  // game loop
  while (d.win.isOpen()) {
    // calculate delta time
    float delta = d.calc_delta();

    // update window title
    d.update_title();

    // event loop
    sf::Event e;
    d.update_mouse();
    d.update_key();
    while (d.win.pollEvent(e)) {
      d.handle_close(e);
      d.update_mouse_event(e);
      d.update_key_event(e);
      d.handle_text(e, buffer);
    }
    if (buffer.size() > text.size()) buffer.pop_back();

    // clear
    d.clear();

    // update
    if (!done) time_passed += delta;

    if (buffer == text){
      time_done = time_passed;
      done = true;
    }

    character_per_sec = float(buffer.size()) / time_passed;

    // draw
    draw_keyboard();

    ui.begin({d.width-200.f, 10.f});

    ui.text(FMT("time: {:.2f}s", time_passed), TopLeft);
    ui.text(FMT("ch/s: {:.2f}", character_per_sec), TopLeft);

    ui.end();

    // d.draw_text({0.f, 0.f}, text, TopLeft, DEFAULT_CHAR_SIZE, sf::Color(255, 255, 255, 100));

    sf::Vector2f text_pos{20.f, 20.f};
    size_t pos_i = 0;
    for (size_t i = 0; i < text.size(); ++i) {
      char ch = text[i];
      
      if (ch == '\r' || ch == '\n'){
	text_pos.y += DEFAULT_CHAR_SIZE + 2.f;
	pos_i = 0;
	continue
      }
      
      sf::Color col = sf::Color::White;
      if (i > buffer.size()-1 || buffer.empty()){
	col.a = 100;
      }
      
      if (!buffer.empty() && i < buffer.size()){
	if (ch != buffer[i]) col = sf::Color::Red;
      }

      const float char_spacing{2.f};
      d.draw_text(text_pos + sf::Vector2f{(float(pos_i) * char_spacing) + float(pos_i) * DEFAULT_CHAR_SIZE/2.f, 0.f}, std::string{ch}, TopLeft, DEFAULT_CHAR_SIZE, col);
      pos_i++;
    }
    

    // display
    d.display();
  }
  // MAIN(MainScene);
  // create("wpm", S_WIDTH, S_HEIGHT, WIDTH, HEIGHT);
  // run();
  return 0;
}
