# Введение #

QHessian – это С++ реализация бинарного web-протокола hessian. QHessian полностью базируется на Qt Framework, что означает, что вам необходим **только Qt, чтобы использовать все возможности qhessian**. QHessian не использует кодогенерацию.

Известные C++ реализации web-протокола hessian:

| Проект | Кодогенерация | Библиотеки |
|:-------------|:---------------------------|:---------------------|
| [hessianorb project](http://code.google.com/p/hessianorb) | Да | CURL |
| [hessiancpp project](http://sourceforge.net/projects/hessiancpp/) | Нет | SSLPP |
| QHessian | Нет | Qt |

# QHessian Properties (свойства) #

Свойства QHessian – это обертки над соответствующими типами сериализации hessian. Свойства разделены на две группы. В namespace QHessian::out содержатся свойства-обертки ответов сервера, а в QHessian::in – свойства-обертки запросов к серверу.

Доступные свойства:
  * **`Null`**: Null обертка для null pointer.
  * **`Boolean`**: Обертка булева типа, принимает только два значения: истина или ложь.
  * **`Integer`**: Обертка числового типа int (от -2,147,483,648 до 2,147,483,647 включительно.
  * **`Long`**: Обертка числового типа long (от -9,223,372,036,854,775,808 до  9,223,372,036,854,775,807 включительно.
  * **`Double`**: Обертка числового типа double (и float). Число с плавающей запятой двойной точности стандарта IEEE 754.
  * **`String`**: Обертка для строки в кодировке UTF8.
  * **`DateTime`**: Представляет конкретное положение во времени с точностью до миллисекунды.
  * **`Binary`**: Обертка для двоичных данных (обычно массив байт).
  * **`BeginCollection`**: Маркер начала коллекции.
  * **`EndCollection`**: Маркер окончания коллекции.
  * **`BeginMap`**: Маркер начала карты.
  * **`HasMoreMap`**: Маркер, показывающий, остались ли еще элементы в карте.
  * **`EndMap`**: Маркер окончания карты.
  * **`BeginObject`**:  Маркер начала объекта.
  * **`EndObject`**:  Маркер окончания объекта.
  * **`Ref`**: Маркер для ссылки на объект.

Каждое свойство может иметь атрибуты name(имя), value(значение) и type(тип).

# Подготовка проекта #

  1. Получите локальную копию репозитория командой <blockquote>hg clone <a href='https://qhessian.googlecode.com/hg/'>https://qhessian.googlecode.com/hg/</a> qhessian </blockquote>
  1. Добавьте в ваши исходники строчку <blockquote>#include "{$path}/QHessian.h"</blockquote>

# Использование QHessian #

Для того, чтобы вызвать удаленный метод, нужно сделать три простых шага:
  1. Создать объект QHessianMethodCall
  1. Установить параметры метода с помощью оператора <<
  1. Инициировать вызов метода функцией invoke

Пример вызова метода **int substract(int a, int b)**:

```
{
	using namespace QHessian::in;
	QHessian::QHessianMethodCall call("substract");
	call << Integer(5) << Integer(4);
	call.invoke(networkManager, url, reciver, SLOT(replySubtractCall()), SLOT(error(int, const QString&)));
}
```

Здесь:
  * **networkManager** – экземпляр класса QNetworkAccessManager
  * **url** – адрес, по которому доступен сервис, предоставляющий данный метод
  * **reciver** – это QObject, который принимает либо ответ сервера, либо сообщение об ошибке. SLOT(replyMyMethodCall()) – слот, принимающий ответ. SLOT(error(int, const QString&)) – слот для обработки ошибок.

Для получения результатов вызова нужно:
  1. Получить экземпляр объекта QHessian::QHessianReturnParser
  1. Разобрать результаты с помощью оператора >>

Например (продолжение примера substract):
```
	void replySubtractCall() {
		qint32 result;

		using namespace QHessian::out;

		QHessian::QHessianReturnParser& parser = *(QHessian::QHessianReturnParser*) QObject::sender();
		parser >> Integer(result); // 1
		parser.deleteLater();
	}
```

## Использование метода QHessian::QHessianReturnParser **peek** ##

Метод **peek** используется, когда заранее не известно какого типа свойство нужно разбирать в данный момент. Например, метод сервера возвращает нетипизированный объект. Этот объект может быть класса Apple(яблоко) или Banana(банан) или любого другого. Для определения типа необходимо использовать метод peek.

```
	if (parser.peek(BeginObject("Apple"))) {
		//can parse Apple type
	} else if (parser.peek(BeginObject("Banana"))) {
		//can parse Banana type
	}
```

С помощью этого метода можно проверить любое свойство, доступное в qhessian.

Смотри так же: [FAQ](http://code.google.com/p/qhessian/wiki/FAQ), [Guide](http://code.google.com/p/qhessian/wiki/Guide)