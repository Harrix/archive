Список функций библиотеки HarrixMathLibraryForTestFunctions
===========================================================

Для тестовых функций
----------------

- Функция выдает принадлежность тестовой функции к классу функций: бинарной, вещественной или иной оптимизации.

```cpp
int HML_ClassOfTestFunction(TypeOfTestFunction Type);
```

- Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов. Включает в себя все тестовые функции вещественной оптимизации.

```cpp
int HML_CountOfFitnessOfTestFunction_Binary(int Dimension);
int HML_CountOfFitnessOfTestFunction_Binary(int Dimension, TypeOfTestFunction Type);
```

- Функция определяет количество вычислений целевой функции для тестовых задач для единообразного сравнения алгоритмов. Включает в себя все тестовые функции вещественной оптимизации.

```cpp
int HML_CountOfFitnessOfTestFunction_Real(int Dimension);
int HML_CountOfFitnessOfTestFunction_Real(int Dimension, TypeOfTestFunction Type);
```

- Служебная функция определяет тестовую функцию для других функций по работе с тестовыми функциями.

```cpp
void HML_DefineTestFunction(TypeOfTestFunction Type);
```

- Функция определяет размерность тестовой задачи для тестовой функции бинарной оптимизации по номеру подзадачи (число подзадач по функции HML_GetCountOfSubProblems_Binary).

```cpp
int HML_DimensionTestFunction_Binary(int i);
int HML_DimensionTestFunction_Binary(int i, TypeOfTestFunction Type);
```

- Функция определяет размерность тестовой задачи для тестовой функции вещественной оптимизации по номеру подзадачи (число подзадач по функции HML_GetCountOfSubProblems_Binary).

```cpp
int HML_DimensionTestFunction_Real(int i);
int HML_DimensionTestFunction_Real(int i, TypeOfTestFunction Type);
```

- Функция определяет значение ошибки по входным параметрам найденного решения в задаче оптимизации для тестовой функции. Включает в себя все тестовые функции бинарной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_ErrorExOfTestFunction_Binary(int *x, int VHML_N);
double HML_ErrorExOfTestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение ошибки по входным параметрам найденного решения в задаче оптимизации для тестовой функции вещественной оптимизации. Включает в себя все тестовые функции вещественной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_ErrorExOfTestFunction_Real(double *x, int VHML_N);
double HML_ErrorExOfTestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение ошибки по значениям целевой функции найденного решения в задаче оптимизации для тестовой функции. Включает в себя все тестовые функции бинарной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VHML_N);
double HML_ErrorEyOfTestFunction_Binary(double FitnessOfx, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение ошибки по значениям целевой функции найденного решения в задаче оптимизации для тестовой функции вещественной оптимизации. Включает в себя все тестовые функции вещественной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_ErrorEyOfTestFunction_Real(double FitnessOfx, int VHML_N);
double HML_ErrorEyOfTestFunction_Real(double FitnessOfx, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение надежности найденного решения в задаче оптимизации для тестовой функции. Включает в себя все тестовые функции бинарной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_ErrorROfTestFunction_Binary(int *x, int VHML_N);
double HML_ErrorROfTestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение надежности найденного решения в задаче оптимизации для тестовой функции вещественной оптимизации. Включает в себя все тестовые функции  вещественной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_ErrorROfTestFunction_Real(double *x, int VHML_N);
double HML_ErrorROfTestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение целевой функции в оптимуме для тестовой функции бинарной оптимизации. Включает в себя все тестовые функции бинарной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_FitnessOfOptimumOfTestFunction_Binary(int VHML_N);
double HML_FitnessOfOptimumOfTestFunction_Binary(int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение целевой функции в оптимуме для тестовой функции вещественной оптимизации. Включает в себя все тестовые функции вещественной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_FitnessOfOptimumOfTestFunction_Real(double VHML_N);
double HML_FitnessOfOptimumOfTestFunction_Real(double VHML_N, TypeOfTestFunction Type);
```

- Функция выдает количество вызовов целевой функции.

```cpp
int HML_GetCountOfFitness();
```

- Функция определяет число подзадач (включая основную задачу) для тестовой функции бинарной оптимизации. Включает в себя все тестовые функции бинарной оптимизации.

```cpp
int HML_GetCountOfSubProblems_Binary();
int HML_GetCountOfSubProblems_Binary(TypeOfTestFunction Type);
```

- Функция определяет число подзадач (включая основную задачу) для тестовой функции вещественной оптимизации. Включает в себя все тестовые функции вещественной оптимизации.

```cpp
int HML_GetCountOfSubProblems_Real();
int HML_GetCountOfSubProblems_Real(TypeOfTestFunction Type);
```

- Функция определяет левые и правые границы допустимой области для тестовой функции вещественной оптимизации. Включает в себя все тестовые функции вещественной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
void HML_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right,int VHML_N);
void HML_LeftAndRightBorderOfTestFunction_Real(double *Left, double *Right, int VHML_N, TypeOfTestFunction Type);
```

- 	Функция сообщает - ищется максимум или минимум в задаче оптимизации для тестовой функции бинарной оптимизации.

```cpp
double HML_MaximumOrMinimumOfTestFunction_Binary();
double HML_MaximumOrMinimumOfTestFunction_Binary(TypeOfTestFunction Type);
```

- 	Функция сообщает - ищется максимум или минимум в задаче оптимизации для тестовой функции вещественной оптимизации.

```cpp
double HML_MaximumOrMinimumOfTestFunction_Real();
double HML_MaximumOrMinimumOfTestFunction_Real(TypeOfTestFunction Type);
```

- Функция определяет на сколько частей нужно делить каждую координату в задаче оптимизации для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации и какая при этом требуется точность для подсчета надежности. Включает в себя все тестовые функции вещественной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VHML_N);
double HML_NumberOfPartsOfTestFunction_Real(int *NumberOfParts, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение оптимума для тестовой функции. Включает в себя все тестовые функции бинарной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_OptimumOfTestFunction_Binary(int *Optimum, int VHML_N);
double HML_OptimumOfTestFunction_Binary(int *Optimum, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет значение оптимума для тестовой функции вещественной оптимизации. Включает в себя все тестовые функции вещественной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_OptimumOfTestFunction_Real(double *Optimum, int VHML_N);
double HML_OptimumOfTestFunction_Real(double *Optimum, int VHML_N, TypeOfTestFunction Type);
```

- Функция определяет точность для подсчета надежности в задаче оптимизации для тестовой функции вещественной оптимизации для алгоритма дискретной оптимизации.

```cpp
double HML_PrecisionOfCalculationsOfTestFunction_Real();
double HML_PrecisionOfCalculationsOfTestFunction_Real(TypeOfTestFunction Type);
```

- Функция обнуляет количество вызовов целевой функции. Обязательно вызвать один раз перед вызовом алгоритмов оптимизации при исследовании эффективности    алгоритмов оптимизации, где требуется контроль числа вызовов целевой функции.

```cpp
void HML_SetToZeroCountOfFitness();
```

- Общая тестовая функция для задач бинарной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_TestFunction_Binary(int *x, int VHML_N);
double HML_TestFunction_Binary(int *x, int VHML_N, TypeOfTestFunction Type);
```

- Общая тестовая функция для задач вещественной оптимизации. Есть функция-переопределение, где пользователь может сам указать тип тестовой функции.

```cpp
double HML_TestFunction_Real(double *x, int VHML_N);
double HML_TestFunction_Real(double *x, int VHML_N, TypeOfTestFunction Type);
```