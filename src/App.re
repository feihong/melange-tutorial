module Route = {
  type t =
    | Home
    | NotFound
    | Counter
    | Playground
    | CelsiusConverter1
    | CelsiusConverter2
    | FoodOrder
    | FoodOrderPolymorphic
    | StyledPpx
    | StackAndRow
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
    | ["food-order"] => FoodOrder
    | ["food-order-poly"] => FoodOrderPolymorphic
    | ["styled-ppx"] => StyledPpx
    | ["stack-and-row"] => StackAndRow
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
    | FoodOrder => "food-order"
    | FoodOrderPolymorphic => "food-order-poly"
    | StyledPpx => "styled-ppx"
    | StackAndRow => "stack-and-row"
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
    | FoodOrder => "Food Order"
    | FoodOrderPolymorphic => "Food Order with Polymorphic Variant"
    | StyledPpx => "styled-ppx"
    | StackAndRow => "Stack and Row"
    | TemperatureConverter => "Temperature Converter"
    | GuessYourNumber => "Guess Your Number"
    | GuessComputerNumber => "Guess Computer's Number";
};

module Title = {
  [@react.component]
  let make = (~label) => <h1> {React.string(label)} </h1>;
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
           FoodOrder,
           FoodOrderPolymorphic,
           StyledPpx,
           StackAndRow,
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
     | CelsiusConverter1 => <> <Subtitle label="Using exception" /> <CelsiusConverter_Exception /> </>
     | CelsiusConverter2 =>
       <>
         <Subtitle label="Using option" />
         <CelsiusConverter_Option />
         <Subtitle label="Using Js.Float.fromString instead of string_of_float_opt" />
         <CelsiusConverter_FloatFromString />
       </>
     | FoodOrder => <FoodOrderDemo />
     | FoodOrderPolymorphic => <FoodOrderPolymorphicDemo />
     | StyledPpx => <> <Counter_Styled /> <CelsiusConverter_Styled /> </>
     | StackAndRow =>
       <>
         <Subtitle label="Stack" />
         <Stack gap=Md align=Left>
           <Box label="Apple" />
           <Box label="Banana Blueberry" />
           <Box label="Chocolate" />
         </Stack>
       </>
     | TemperatureConverter => <TemperatureConverter />
     | GuessYourNumber => <GuessYourNumber />
     | GuessComputerNumber => <GuessComputerNumber />
     | NotFound => <div />
     }}
  </div>;
};
