# cpp-ai-learn

Учебный C++ проект: алгоритмические задачи, STL-практика, маленькие программы по языку. Используется как площадка для C++ track при подготовке к ШАД Яндекса (https://shad.yandex.ru/enroll). Make/CMake-структура универсальна — подойдёт как шаблон для любых C++ упражнений с тестами и санитайзерами из коробки.

## Стек

- **C++23** + Clang (Homebrew LLVM) + Ninja
- **Google Test** и **Google Benchmark** через FetchContent
- **AddressSanitizer + UBSan** включены в Debug
- **clang-format + clangd + clang-tidy** настроены, `compile_commands.json` генерируется автоматически
- Мульти-проектная структура: каждый подпроект в `src/<name>/` со своим `CMakeLists.txt`

## Требования

```bash
# macOS (Homebrew)
brew install cmake ninja llvm

# Опционально
brew install gnuplot            # визуализация из C++

# Python-окружение для sanity check ML-проектов (pip вне venv заблокирован на macOS)
python3 -m venv .venv
source .venv/bin/activate
pip install numpy scikit-learn
```

| Зависимость | Минимальная версия | Назначение |
|---|---|---|
| CMake | 4.0 | Система сборки |
| Ninja | любая | Быстрый бэкенд для CMake |
| LLVM/Clang | 17+ | Компилятор (C++23, sanitizers) |
| gnuplot | любая | Визуализация (опционально) |

## Быстрый старт

```bash
make setup              # проверить что все зависимости установлены
make init               # сгенерировать CMake + compile_commands.json
make build              # собрать всё
make test               # запустить тесты
make run TARGET=hello_world  # собрать и запустить одну цель
```

## Команды Makefile

| Команда | Описание |
|---|---|
| `make init` | Инициализация проекта (CMake + compile_commands) |
| `make build` | Сборка всех целей |
| `make run TARGET=<name>` | Сборка и запуск одной цели |
| `make new TARGET=<name>` | Создать новый подпроект из шаблона |
| `make test` | Запуск всех тестов (ctest) |
| `make bench` | Запуск бенчмарков |
| `make clean` | Полная очистка build/ |
| `make clean-target` | Очистка одной цели |
| `make rebuild` | clean + build |
| `make rebuild-target` | clean-target + build target |
| `make release TARGET=<name>` | Сборка в Release без санитайзеров |
| `make leaks TARGET=<name>` | Проверка утечек через macOS `leaks` |
| `make setup` | Проверка системных зависимостей |
| `make help` | Показать все доступные команды |

### Переменные

| Переменная | По умолчанию | Описание |
|---|---|---|
| `TARGET` | `hello_world` | Цель для сборки/запуска |
| `BUILD_TYPE` | `Debug` | `Debug` или `Release` |
| `ASAN` | `ON` | AddressSanitizer |
| `UBSAN` | `ON` | UndefinedBehaviorSanitizer |

## Структура проекта

```
.
├── CMakeLists.txt              # Корневой CMake (зависимости, настройки компиляции)
├── Makefile                    # Удобные команды
├── cmake/
│   └── ProjectWarnings.cmake   # Флаги предупреждений
├── libs/                       # Общие библиотеки между подпроектами
├── src/                        # Подпроекты
│   └── hello_world/            # Пример подпроекта
│       ├── CMakeLists.txt
│       ├── main.cpp
│       └── tests/
│           └── test_main.cpp
├── datasets/                   # Датасеты (CSV, текстовые файлы)
├── scripts/                    # Вспомогательные скрипты
├── .clang-format               # Настройки форматирования
├── .clang-tidy                 # Настройки линтера
└── .clangd                     # Настройки LSP
```

## Как добавить новый подпроект

```bash
make new TARGET=my_app
```

Создаст:
- `src/my_app/main.cpp` — точка входа
- `src/my_app/CMakeLists.txt` — сборка + тесты (GTest)
- `src/my_app/tests/test_main.cpp` — заготовка теста

Подпроект автоматически подхватится при следующей сборке (`make build`).

## Как добавить общую библиотеку

Общие библиотеки, используемые несколькими подпроектами, размещаются в `libs/`.
Папка `libs/` уже добавлена в `include_directories`, поэтому заголовки доступны
из любого подпроекта через `#include "my_lib/my_lib.h"`.

## Конфигурация CMake

| Опция | По умолчанию | Описание |
|---|---|---|
| `ENABLE_ASAN` | `OFF` | AddressSanitizer (включается через Makefile) |
| `ENABLE_UBSAN` | `OFF` | UndefinedBehaviorSanitizer (включается через Makefile) |
| `ENABLE_NATIVE_ARCH` | `ON` | Оптимизация под Apple Silicon |
| `WITH_BENCHMARK` | `ON` | Подключить Google Benchmark |

## Учебный workflow и roadmap

Подготовка ведётся по детальному ШАД-роадмепу в Obsidian (vault лежит вне этого репо). Для синхронизации роадмепа с daily/weekly заметками подключён subagent `shad-planner` — описание в [.claude/agents/shad-planner.md](.claude/agents/shad-planner.md). Конкретные пути к vault'у и шаблоны daily/weekly хранятся там же и в [CLAUDE.md](CLAUDE.md), а не в публичной части репо.

### Триггеры в Claude Code

| Фраза | Режим | Что делает |
|---|---|---|
| `daily по ШАД`, `план на сегодня`, `следующая задача`, `что дальше по плану` | `daily` | Находит первый день с незакрытыми задачами в активном плане фазы, создаёт daily-заметку и вставляет задачи дня. Делает sync-back: чекбоксы, закрытые в последней daily, проставляются в основном плане. |
| `weekly по ШАД`, `план на неделю`, `обзор недели` | `weekly` | Создаёт weekly-заметку для текущей ISO-недели с целью и результатом из роадмепа, статусом дней и dataview-блоком статистики. |
| `детализируй фазу`, `начнём фазу N` | `phase-detail` | По высокоуровневой фазе (`0N - Phase N - <название>.md`) генерирует детальный план по дням (`NNa - Phase N - Детальный план по дням.md`) в стиле Phase 1. |
| `где я по ШАД`, `статус`, `прогресс` | `status` | Показывает активную фазу, неделю, следующий день, последние daily/weekly, проседающие темы из Topic Map. |

### Источник правды

Прогресс по плану — чекбоксы `- [ ]` / `- [x]` в файле `NNa - Phase N - Детальный план по дням.md` активной фазы. Отдельной БД нет; sync-back подтягивает закрытые задачи из daily в этот файл.

### Метрики daily

Frontmatter daily-заметок:

- Обязательные: `shad_hours`, `shad_math_tasks`, `shad_algo_tasks`, `cpp_hours`.
- Опциональные: `shad_probe_minutes`, `shad_error_log`, `shad_explain`.

`cpp_hours` — это время на C++ как язык/toolchain/конспекты, в том числе работа в этом репо. `shad_algo_tasks` — алгоритмические задачи, в том числе решённые здесь.

### Адаптация под другой роадмеп

Структура агента не привязана к ШАДу: достаточно поменять пути и набор полей frontmatter в [.claude/agents/shad-planner.md](.claude/agents/shad-planner.md), формат заголовков дней/недель оставить тем же — `## День N - тема` / `# Неделя N - название`.

## Applied project: Mini-Database

Помимо контестных задач, в этом репо живёт небольшой applied — учебная Mini-DB на современном C++ по образцу [cstack/Let's Build a Simple Database](https://cstack.github.io/db_tutorial/), переписанному с C на C++17/20/23. Цель — учить язык на осмысленном проекте, а не только на россыпи LeetCode-задач.

Подпроект создаётся через `make new TARGET=mini_db` (Phase 1, неделя 1).

### Скоп

Vertical slice: REPL → парсер минимального SQL (`INSERT`, `SELECT`) → in-memory table → file persistence → pager → B-tree primary key. Без transactions, recovery, multi-user, optimizer, JOIN.

### Темп

| Фаза подготовки | Объём applied | Что делается |
|---|---|---|
| Phase 1 (нед. 1-8) | ~30 мин/нед, по воскресеньям | warm-up: in-memory KV REPL с file save/load, готовая стартовая точка |
| Phase 2 (нед. 9-20) | 1.5-2 ч/нед | основная работа по cstack parts 1-13 |
| Phase 3 (нед. 21-32) | ~1 ч/нед | полировка: применение тем Phase 3 (structs, comparators, профилирование) |
| Phase 4-5 (нед. 33-52) | пауза | всё время — пробники и ремонт перед экзаменом |

### Правило приоритета

Applied — мотивационный довесок, не самостоятельный трек. **Отрезается первым** при просадке по математике или алгоритмам. Если хочется углубиться (transactions, B+tree internals, query planner) — это сигнал стоп: drift в инженерную тему уведёт от подготовки. Углубление — после поступления через CMU 15-445 + BusTub.

### После Mini-DB

Если cstack пройден до конца Phase 2 без задержек, в Phase 3 на свободные часы — **не** углубляться в Mini-DB, а взять короткий альтернативный applied (8-15 ч): mini-interpreter (Crafting Interpreters), parser combinators, mini ray tracer, self-balancing dictionary. Список — в `09 - C++ Track.md` (Obsidian vault, не в этом репо).

Подробный план по неделям и темам C++, которые закрывает каждый этап applied, — в C++ Track роадмепа.
