#include "Lion2App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<Lion2App>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

Lion2App::Lion2App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  Lion2App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  Lion2App::associateSyntax(_syntax, _action_factory);
}

Lion2App::~Lion2App()
{
}

// External entry point for dynamic application loading
extern "C" void Lion2App__registerApps() { Lion2App::registerApps(); }
void
Lion2App::registerApps()
{
  registerApp(Lion2App);
}

// External entry point for dynamic object registration
extern "C" void Lion2App__registerObjects(Factory & factory) { Lion2App::registerObjects(factory); }
void
Lion2App::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void Lion2App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Lion2App::associateSyntax(syntax, action_factory); }
void
Lion2App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
