#pragma once
#include <MoGE/MoGE.hpp>

namespace momo {

#define LAYOUTS_CAP 256
struct UI {
  struct Layout {
    enum class Kind { Horz, Vert };
    Kind kind;
    Vec2 pos;
    Vec2 size;
    Vec2 padding;
    Layout();

    Vec2 availablePos() const;
    void pushWidget(Vec2 size);
  };

  int active_id;
  Layout layouts[LAYOUTS_CAP];
  size_t layouts_count;
  static Vec2 btnPadding;
  int hoverTime;
  int hoverTimeMax;

  UI();

  void pushLayout(Layout layout);
  Layout popLayout();
  Layout *topLayout();
  void beginLayout(Layout::Kind kind = Layout::Kind::Vert);
  void endLayout();

  void begin(Vec2 pos, Layout::Kind kind = Layout::Kind::Vert);
  bool btn(std::string text, size_t charSize, size_t id = 0,
           Color col = Color(200, 200, 200));
  bool sprBtn(Sprite &spr, size_t id);
  float slider(float val, float min, float max, float size,
               Color col = Color(200, 200, 200), size_t id = 0,
               std::string text = "");
  void text(std::string _text, size_t charSize, Color col = WHITE);
  void spr(Sprite &spr);
  void end();
};

}; // namespace momo
