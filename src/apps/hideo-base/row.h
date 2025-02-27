#pragma once

#include <karm-ui/input.h>

namespace Hideo {

Ui::Child card(Ui::Child child);

inline auto card() {
    return [](Ui::Child child) {
        return card(child);
    };
}

Ui::Child card(Ui::Children children);

static inline Ui::Child card(Ui::Child child, Meta::Same<Ui::Child> auto... children) {
    return card({child, children...});
}

Ui::Child row(Ui::Child child);

Ui::Child row(Opt<Ui::Child> leading, String title, Opt<String> subtitle, Opt<Ui::Child> trailing);

Ui::Child titleRow(String t);

Ui::Child pressableRow(Ui::OnPress onPress, Opt<Ui::Child> leading, String title, Opt<String> subtitle, Opt<Ui::Child> trailing);

Ui::Child buttonRow(Ui::OnPress onPress, Mdi::Icon i, String title, String subtitle);

Ui::Child buttonRow(Ui::OnPress onPress, String title, String text);

Ui::Child toggleRow(bool value, Ui::OnChange<bool> onChange, String title);

Ui::Child checkboxRow(bool value, Ui::OnChange<bool> onChange, String title);

Ui::Child radioRow(bool value, Ui::OnChange<bool> onChange, String title);

Ui::Child sliderRow(f64 value, Ui::OnChange<f64> onChange, String title);

Ui::Child colorRow(Gfx::Color color, Ui::OnChange<Gfx::Color> onChange, String title);

Ui::Child treeRow(Opt<Ui::Child> leading, String title, Opt<String> subtitle, Ui::Child child);

Ui::Child treeRow(Opt<Ui::Child> leading, String title, Opt<String> subtitle, Ui::Children children);

} // namespace Hideo
