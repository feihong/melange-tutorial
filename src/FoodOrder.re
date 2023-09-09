type sandwich =
  | Portabello
  | Ham
  | Unicorn;

type burger = {
  tomatoes: bool,
  lettuce: bool,
  bacon: int,
  onions: int,
  cheese: int,
};

type menuItem =
  | Hotdog
  | Sandwich(sandwich)
  | Burger(burger);

type order = array(menuItem);

let sandwichToString = sandwich => {
  let sandwich =
    switch (sandwich) {
    | Portabello => {js|🍄|js}
    | Ham => {js|🐷|js}
    | Unicorn => {js|🦄|js}
    };
  sandwich ++ " Sandwich";
};

let burgerToString = ({lettuce, tomatoes, bacon, onions, cheese}) => {
  let multi = (str, n) => Array.make(n, str) |> Js.Array.joinWith("");

  let listStr =
    [|
      lettuce ? {js|🥬|js} : "",
      tomatoes ? {js|🍅|js} : "",
      multi({js|🥓|js}, bacon),
      multi({js|🧅|js}, onions),
      multi({js|🧀|js}, cheese),
    |]
    |> Js.Array.filter(str => str != "")
    |> Js.Array.joinWith(", ");
  {js|🍔 (|js} ++ listStr ++ ")";
};

let itemToString = item =>
  switch (item) {
  | Hotdog => {js|🌭|js}
  | Sandwich(sandwich) => sandwichToString(sandwich)
  | Burger(burger) => burgerToString(burger)
  };

[@react.component]
let make = (~order: order) =>
  <ul style={ReactDOMStyle.make(~fontSize="2em", ())}>
    {order
     |> Array.mapi((idx, item) =>
          <li key={"item-" ++ string_of_int(idx)}> {item |> itemToString |> React.string} </li>
        )
     |> React.array}
  </ul>;
