#ifndef LION2APP_H
#define LION2APP_H

#include "MooseApp.h"

class Lion2App;

template<>
InputParameters validParams<Lion2App>();

class Lion2App : public MooseApp
{
public:
  Lion2App(InputParameters parameters);
  virtual ~Lion2App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* LION2APP_H */
