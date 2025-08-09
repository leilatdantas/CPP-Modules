# CPP-08 - Templated Containers, Iterators and Algorithms

Este módulo aprofunda o conhecimento sobre **containers STL**, **iteradores** e **algoritmos**, focando na criação de estruturas de dados customizadas que se integram com o ecosistema STL.

## 📚 Conceitos Abordados

- **STL Containers**: vector, list, deque, stack
- **STL Iterators**: forward, bidirectional, random access
- **STL Algorithms**: find, sort, min_element, max_element
- **Template Specialization**: Adaptando templates para casos específicos
- **Container Adapters**: Como criar adaptadores de container
- **Iterator Traits**: Características dos iteradores

## 🎯 Exercícios

### Ex00 - Easy find
**Arquivos**: `easyfind.hpp`, `main.cpp`

Implementa uma função template que encontra um valor inteiro em qualquer container STL:

```cpp
template<typename T>
typename T::iterator easyfind(T& container, int value);
```

**Características**:
- ✅ Funciona com vector, list, deque e outros containers
- ✅ Usa `std::find()` internamente
- ✅ Lança exceção se elemento não encontrado
- ✅ Suporte a containers const e não-const
- ✅ Retorna iterador para o elemento encontrado

**Funcionalidades**:
- Busca em diferentes tipos de container
- Tratamento de exceções personalizado
- Teste de performance com containers grandes

### Ex01 - Span
**Arquivos**: `Span.hpp`, `Span.cpp`, `main.cpp`

Implementa uma classe que armazena N inteiros e pode calcular spans (diferenças):

```cpp
class Span
{
public:
    Span(unsigned int N);
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;
    
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
};
```

**Características**:
- ✅ Capacidade limitada definida no construtor
- ✅ Adicionar números individuais ou por range
- ✅ Calcular menor e maior diferença entre números
- ✅ Exceções para casos inválidos
- ✅ Otimização para grandes quantidades de dados

**Funcionalidades**:
- Shortest span: menor diferença entre quaisquer dois números
- Longest span: diferença entre maior e menor número
- Range insertion: adicionar múltiplos números de uma vez
- Exception safety: controle rigoroso de erros

### Ex02 - Mutated abomination
**Arquivos**: `MutantStack.hpp`, `main.cpp`

Cria um stack que também pode ser iterado, combinando std::stack com iteradores:

```cpp
template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename Container::iterator iterator;
    
    iterator begin();
    iterator end();
    // ... outros tipos de iteradores
};
```

**Características**:
- ✅ Herda de std::stack mantendo funcionalidades LIFO
- ✅ Adiciona iteradores para traversal
- ✅ Suporte a iteradores forward e reverse
- ✅ Compatível com algoritmos STL
- ✅ Container subjacente configurável

**Funcionalidades**:
- Operações de stack normais (push, pop, top)
- Iteração através dos elementos
- Uso com algoritmos STL (sort, find, etc.)
- Diferentes tipos de iteradores (const, reverse)

## 🔧 Compilação e Teste

### Compilar todos os exercícios:
```bash
make
```

### Compilar exercício específico:
```bash
make -C ex00  # ou ex01, ex02
```

### Executar testes:
```bash
make test
```

### Limpar arquivos:
```bash
make clean    # Remove objetos
make fclean   # Remove executáveis
make re       # Recompila tudo
```

## 📝 Saída Esperada

### Ex00 - easyfind:
```
=== Teste com std::vector ===
Vector: 1 2 3 4 5 6 7 8 9 10
Elemento 5 encontrado na posição: 4
Valor encontrado: 5
Elemento 15: Element not found in container

=== Teste com std::list ===
List: 10 9 8 7 6 5 4 3 2 1
Elemento 3 encontrado
Valor encontrado: 3
```

### Ex01 - span:
```
=== Teste Básico ===
Números adicionados: 6, 3, 17, 9, 11
Shortest span: 2
Longest span: 14

=== Teste de Exceções ===
Tentando calcular span com container vazio...
Exceção capturada: Cannot calculate span: need at least 2 numbers
```

### Ex02 - mutantstack:
```
=== Teste Operações Básicas ===
Stack vazia? Sim
Tamanho: 0
Após adicionar 5 e 17:
Topo: 17
Tamanho: 2

=== Teste Iteradores ===
Stack contents (iterador normal): 5 17 3 5 737 0
Stack contents (iterador reverso): 0 737 5 3 17 5
```

## 💡 Conceitos Importantes

### Iterator Categories
- **Input Iterator**: Leitura sequencial única
- **Output Iterator**: Escrita sequencial única  
- **Forward Iterator**: Leitura/escrita sequencial múltipla
- **Bidirectional Iterator**: Como forward, mas vai em ambas direções
- **Random Access Iterator**: Acesso direto a qualquer posição

### STL Integration
Os containers customizados seguem convenções STL:
```cpp
typedef typename Container::iterator iterator;
typedef typename Container::value_type value_type;
typedef typename Container::size_type size_type;
```

### Exception Safety
- **Basic Guarantee**: Objeto fica em estado válido após exceção
- **Strong Guarantee**: Operação é atomic (sucesso total ou rollback)
- **No-throw Guarantee**: Operação nunca lança exceção

### Template Metaprogramming
```cpp
template<typename Iterator>
void addNumbers(Iterator begin, Iterator end)
{
    // std::distance calcula automaticamente o número de elementos
    typename std::iterator_traits<Iterator>::difference_type distance;
    distance = std::distance(begin, end);
}
```

## 🔍 Detalhes de Implementação

### Performance Considerations
- **Ex00**: O(n) para busca linear em containers
- **Ex01**: O(n log n) para shortest span (devido ao sort)
- **Ex02**: O(1) para operações de stack, O(n) para iteração

### Memory Management
- Uso de containers STL para gerenciamento automático
- RAII em todas as classes
- Exception safety em operações críticas

### Algorithm Compatibility
- MutantStack funciona com std::sort, std::find, etc.
- Iteradores seguem padrões STL
- Compatible com range-based for loops (C++11+)

### Template Flexibility
- easyfind funciona com qualquer container que tenha iteradores
- Span aceita qualquer tipo de iterador
- MutantStack permite diferentes containers subjacentes

## 🚀 Extensões Possíveis

- **Ex00**: Busca binária para containers ordenados
- **Ex01**: Span para tipos diferentes de int
- **Ex02**: MutantQueue, MutantPriorityQueue

Este módulo prepara para conceitos avançados como generic programming e metaprogramming, essenciais para C++ moderno e desenvolvimento de bibliotecas.
