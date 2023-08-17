let getValueFromEvent = (evt): string => ReactEvent.Form.target(evt)##value;

let convert = celsius => 9.0 /. 5.0 *. celsius +. 32.0;

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");
  let (fahrenheit, setFahrenheit) = React.useState(() => "?");

  <div>
    <input
      value=celsius
      onChange={evt => {
        let newCelsius = getValueFromEvent(evt);
        setCelsius(_ => newCelsius);
        switch (newCelsius |> float_of_string |> convert |> Js.Float.toFixedWithPrecision(~digits=2)) {
        | exception _ => setFahrenheit(_ => "error")
        | newFahrenheit => setFahrenheit(_ => newFahrenheit)
        };
      }}
    />
    {React.string({js|°C = |js})}
    {(fahrenheit == "error" ? fahrenheit : fahrenheit ++ {js| °F|js}) |> React.string}
  </div>;
};
