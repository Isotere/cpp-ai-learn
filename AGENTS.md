# AGENTS.md - cpp-ai-learn

@/Users/vyutilikov/.codex/RTK.md

Use caveman mode. Cut filler. Keep technical accuracy.

## User Permission Rules

- Never edit code, text, docs, config, generated files, or memory files without explicit user permission.
- Never run commands without explicit user permission.
- User may grant permission for one action, one session, one task, or specific command/edit classes.
- Before using broad permission, ask clearly what scope is being granted.
- If permission scope is unclear, ask before acting.

## Project

Учебный C++ проект - площадка для C++ track из ШАД-роадмепа:
алгоритмические задачи (LeetCode/Yandex Training/Codeforces), маленькие учебные
программы по STL и языку, локальные тесты.

Цель пользователя - поступление в ШАД Яндекса (https://shad.yandex.ru/enroll),
набор 2027. Код пишется идиоматично, но без избыточных абстракций. Приоритет:
корректность и читаемость контестного решения.

Роадмеп (Obsidian vault):

```text
~/Library/Mobile Documents/iCloud~md~obsidian/Documents/CommonIcloud/ШАД/PrepareRoadmap/
```

Основные файлы роадмепа:

- `00 - SHAD Roadmap.md` - обзор и навигация.
- `01a - Phase 1 - Детальный план по дням.md` - текущий детальный план (8 недель).
- `09 - C++ Track.md` - отдельный маршрут по C++.
- `06 - Ресурсы и ссылки.md` - учебники и тренажеры.
- `Dashboard.md` - Obsidian-дашборд с Tracker/Dataview.

## Build

```bash
make init          # первичная инициализация (CMake + Ninja + compile_commands)
make build         # сборка всех целей
make run TARGET=x  # сборка и запуск одной цели
make test          # ctest
make bench         # Google Benchmark
make new TARGET=x  # создать новый подпроект из шаблона
```

Компилятор: Homebrew LLVM (`/opt/homebrew/opt/llvm/bin/clang++`).
Генератор: Ninja. Стандарт: C++23.

## Structure

```text
src/<target>/           - подпроекты (каждый со своим CMakeLists.txt)
src/<target>/tests/     - тесты (GTest)
libs/                   - header-only библиотеки
datasets/               - CSV-датасеты (Iris, Boston Housing, Wine)
cmake/                  - CMake-модули (ProjectWarnings.cmake)
bin/                    - собранные бинарники (gitignored)
build/                  - build directory (gitignored)
.venv/                  - Python venv для numpy/sklearn sanity checks
```

Новый подпроект: `make new TARGET=my_app` создает `src/my_app/` с `main.cpp`,
`CMakeLists.txt` и тестами.

## Code Style

- Clang-format: LLVM style (`.clang-format` в корне).
- Clang-tidy: настроен (`.clang-tidy` в корне).
- Warnings: `-Wall -Wextra -Wpedantic -Werror` + дополнительные (см. `cmake/ProjectWarnings.cmake`).
- Sanitizers: ASan и UBSan включены по умолчанию в Debug.

## Dependencies

FetchContent:

- Google Test v1.17.0.
- Google Benchmark v1.9.5.

## Learning Context

Сейчас Phase 1 ШАД-роадмепа (8 недель, диагностика и фундамент): C++ toolchain
(`clang++`/`clangd`/`clang-tidy`), стандартные include без `bits/stdc++.h`,
базовый STL (`vector`, `string`, `map`/`unordered_map`, `set`,
`stack`/`queue`/`deque`, `priority_queue`, `sort`/`lower_bound`),
функции/ссылки/`const`, namespaces. Параллельно - математика (линал, матан,
комбинаторика, вероятность) и алгоритмы (массивы, hash, prefix sums,
two pointers, binary search, рекурсия, BFS/DFS).

К концу Phase 1: рабочий C++ шаблон для контестных задач, журнал ошибок,
Topic Map с green/yellow/red статусами по темам, 35-50 алгоритмических задач,
60-90 математических.

Цели Phase 1 - это не mini-Matrix/mini-ML. Старый AI-роадмеп с research-уровнем
(CUDA/LibTorch/PyTorch C++ extensions) больше не активен.

При работе над задачами сверяйся с детальным планом в `01a - Phase 1`. Для
C++-специфики - `09 - C++ Track`.

## Progress Tracking

Daily Notes в Obsidian:

```text
~/Library/Mobile Documents/iCloud~md~obsidian/Documents/CommonIcloud/Daily Notes/
```

Имена: `YYYY-MM-DD.md`.

Frontmatter daily - обязательные поля: `shad_hours`, `shad_math_tasks`,
`shad_algo_tasks`, `cpp_hours`. Опциональные: `shad_probe_minutes`,
`shad_error_log`, `shad_explain`, `leetcode_solved`, `piano_minutes`.

Weekly Notes:

```text
Daily Notes/Weekly/GGGG-[W]WW.md
```

ISO-неделя, пример: `2026-W17.md`.

Dashboard:

```text
ШАД/PrepareRoadmap/Dashboard.md
```

Для daily/weekly планирования и sync-back с роадмепом используй проектного
агента-инструкцию `.agents/shad-planner.md`.

