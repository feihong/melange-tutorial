module Route = {
  type t =
    | Home
    | NotFound
    | Counter
    | Playground
    | CelsiusConverter1
    | CelsiusConverter2
    | TemperatureConverter
    | GuessYourNumber
    | GuessComputerNumber;

  let fromPath = path =>
    switch (path) {
    | [] => Home
    | ["counter"] => Counter
    | ["playground"] => Playground
    | ["celsius-1"] => CelsiusConverter1
    | ["celsius-2"] => CelsiusConverter2
    | ["temp-converter"] => TemperatureConverter
    | ["guess-your-number"] => GuessYourNumber
    | ["guess-computer-number"] => GuessComputerNumber
    | _ => NotFound
    };

  let toPath =
    fun
    | Home => ""
    | NotFound => "not-found"
    | Counter => "counter"
    | Playground => "playground"
    | CelsiusConverter1 => "celsius-1"
    | CelsiusConverter2 => "celsius-2"
    | TemperatureConverter => "temp-converter"
    | GuessYourNumber => "guess-your-number"
    | GuessComputerNumber => "guess-computer-number";

  let toTitle =
    fun
    | Home => "Melange Tutorial"
    | NotFound => "Not found"
    | Counter => "Counter"
    | Playground => "Playground"
    | CelsiusConverter1 => "Celsius Converter, pt 1"
    | CelsiusConverter2 => "Celsius Converter, pt 2"
    | TemperatureConverter => "Temperature Converter"
    | GuessYourNumber => "Guess Your Number"
    | GuessComputerNumber => "Guess Computer's Number";
};

module Title = {
  [@react.component]
  let make = (~label) => <h1> {React.string(label)} </h1>;
};

module Subtitle = {
  [@react.component]
  let make = (~label) => <h2> {React.string(label)} </h2>;
};

module Link = {
  [@react.component]
  let make = (~route: Route.t) =>
    <a
      href=""
      onClick={evt => {
        ReactEvent.Mouse.preventDefault(evt);
        route |> Route.toPath |> ReasonReactRouter.push;
      }}>
      {route |> Route.toTitle |> React.string}
    </a>;
};

module Home = {
  [@react.component]
  let make = () => {
    <div>
      <ul>
        {[|
           Counter,
           Playground,
           CelsiusConverter1,
           CelsiusConverter2,
           TemperatureConverter,
           GuessYourNumber,
           GuessComputerNumber,
         |]
         |> Array.map(route => <li key={Route.toPath(route)}> <Link route /> </li>)
         |> React.array}
      </ul>
    </div>;
  };
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = Route.fromPath(url.path);

  <div>
    <Title label={Route.toTitle(route)} />
    {switch (route) {
     | Home => <Home />
     | Counter => <Counter />
     | Playground => <> <Subtitle label="Counter using float" /> <CounterFloat /> </>
     | CelsiusConverter1 => <CelsiusConverter_Exception />
     | CelsiusConverter2 =>
       <>
         <CelsiusConverter_Option />
         <Subtitle label="Add prop with default value" />
         <CelsiusConverter_PropDefaultValue value="25" />
         <Subtitle label="Add optional prop" />
         <CelsiusConverter_PropOptional value=26.0 />
         <Subtitle label="Using Js.Float.fromString" />
         <CelsiusConverter_FloatFromString value="28" />
       </>
     | TemperatureConverter => <TemperatureConverter />
     | GuessYourNumber => <GuessYourNumber />
     | GuessComputerNumber => <GuessComputerNumber />
     | NotFound => <div />
     }}
  </div>;
};
