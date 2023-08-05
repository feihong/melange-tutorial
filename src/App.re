module Route = {
  type t =
    | Home
    | NotFound
    | Counter
    | TemperatureConverter
    | GuessYourNumber
    | GuessComputerNumber;

  let pathToRoute = path =>
    switch (path) {
    | [] => Home
    | ["counter"] => Counter
    | ["temp-converter"] => TemperatureConverter
    | ["guess-your-number"] => GuessYourNumber
    | ["guess-computer-number"] => GuessComputerNumber
    | _ => NotFound
    };

  let routeToPath =
    fun
    | Home => ""
    | NotFound => "not-found"
    | Counter => "counter"
    | TemperatureConverter => "temp-converter"
    | GuessYourNumber => "guess-your-number"
    | GuessComputerNumber => "guess-computer-number";
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
        route |> Route.routeToPath |> ReasonReactRouter.push;
      }}>
      {(
         switch (route) {
         | Home
         | NotFound => ""
         | Counter => "Counter"
         | TemperatureConverter => "Temperature converter"
         | GuessYourNumber => "Guess your number"
         | GuessComputerNumber => "Guess the computer's number"
         }
       )
       |> React.string}
    </a>;
};

module Home = {
  [@react.component]
  let make = () => {
    <div>
      <Title label="Melange Tutorial" />
      <ul>
        {[|Counter, TemperatureConverter, GuessYourNumber, GuessComputerNumber|]
         |> Array.map(route => <li key={Route.routeToPath(route)}> <Link route /> </li>)
         |> React.array}
      </ul>
    </div>;
  };
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  <div>
    {switch (Route.pathToRoute(url.path)) {
     | Home => <Home />
     | Counter =>
       <div>
         <Title label="Counter" />
         <Subtitle label="Counter using integer" />
         <Counter />
         <Subtitle label="Counter using float" />
         <CounterFloat />
       </div>
     | TemperatureConverter =>
       <div>
         <Title label="Temperature converter" />
         <Subtitle label="Celsius to Fahrenheit converter" />
         <CelsiusConverter />
         <Subtitle label="Bidirectional converter" />
         <TemperatureConverter />
       </div>
     | GuessYourNumber => <div> <Title label="Guess your number" /> </div>
     | GuessComputerNumber => <div> <Title label="Guess the computer's number" /> <GuessComputerNumber /> </div>
     | NotFound => <Title label="Not found!" />
     }}
  </div>;
};
