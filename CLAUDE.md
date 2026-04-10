# CLAUDE.md — cpp-ai-learn

## Проект

Учебный C++ проект по роадмапу "AI + C++ Research". Цель — освоить C++17/20/23, линейную алгебру, ML с нуля, CUDA, LibTorch. Код пишется для обучения, но должен быть идиоматичным и production-quality.

Роадмап (Obsidian vault):
`~/Library/Mobile Documents/iCloud~md~obsidian/Documents/CommonIcloud/AI/RoadmapCPP/`

Основные файлы роадмапа:
- `00 - AI + C++ Roadmap.md` — обзор и навигация
- `01a - Phase 1 - Детальный план по дням.md` — текущий детальный план (10 недель)
- `Dashboard.md` — Obsidian-дашборд с Tracker/Dataview

## Сборка

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

## Структура

```
src/<target>/           — подпроекты (каждый со своим CMakeLists.txt)
src/<target>/tests/     — тесты (GTest)
libs/                   — header-only библиотеки
datasets/               — CSV-датасеты (Iris, Boston Housing, Wine)
cmake/                  — CMake-модули (ProjectWarnings.cmake)
bin/                    — собранные бинарники (gitignored)
build/                  — build directory (gitignored)
.venv/                  — Python venv для numpy/sklearn sanity checks
```

Новый подпроект: `make new TARGET=my_app` создаёт `src/my_app/` с main.cpp, CMakeLists.txt и тестами.

## Стиль кода

- Clang-format: LLVM style (`.clang-format` в корне)
- Clang-tidy: настроен (`.clang-tidy` в корне)
- Warnings: `-Wall -Wextra -Wpedantic -Werror` + дополнительные (см. `cmake/ProjectWarnings.cmake`)
- Sanitizers: ASan и UBSan включены по умолчанию в Debug

## Зависимости (FetchContent)

- Google Test v1.17.0
- Google Benchmark v1.9.5

## Контекст обучения

Сейчас Phase 1 (фундамент): основы C++, STL, RAII, линейная алгебра, CLRS, LeetCode.
К концу Phase 1 должны быть готовы: Mini-Matrix (своя линалг), Mini-ML Toolkit (CLI с regression/k-means/PCA), Data Pipeline (CSV reader, plotting).

При работе над задачами сверяйся с детальным планом в роадмапе — там расписано по дням и неделям, что именно делать.

## Трекинг прогресса

Daily Notes в Obsidian (`~/Library/Mobile Documents/iCloud~md~obsidian/Documents/CommonIcloud/Daily Notes/`).
Frontmatter-поля: `cpp_hours`, `leetcode_solved`, `piano_minutes`.
Dashboard: `AI/RoadmapCPP/Dashboard.md`.
